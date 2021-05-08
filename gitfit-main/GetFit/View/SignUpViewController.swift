//
//  SignUpViewController.swift
//  GetFit
//
//  Created by iosdev on 23.4.2021.
//

import UIKit
import FirebaseAuth
import Firebase
import FirebaseFirestore

class SignUpViewController: UIViewController {
    
    @IBOutlet weak var firstName: UITextField!
    @IBOutlet weak var lastName: UITextField!
    @IBOutlet weak var emaiL: UITextField!
    @IBOutlet weak var password: UITextField!
    @IBOutlet weak var errorLabel: UILabel!
    @IBOutlet weak var signUpButton: UIButton!
    @IBOutlet weak var loginButton: UIButton!
    @IBOutlet weak var signupLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        errorLabel.alpha = 0
        
        signupLabel.text = "SignUp to GetFit".localized()
        
        signUpButton.setTitle("Signup".localized(), for: .normal)
        loginButton.setTitle("Login?".localized(), for: .normal)
    }
    
    // Check the fields and validate that the data is correct. If everything is correct, this method returns nil. Otherwise, it returns the error message
    func validateFields() -> String? {
        
        // Check that all fields are filled in
        if firstName.text?.trimmingCharacters(in: .whitespacesAndNewlines) == "" ||
            lastName.text?.trimmingCharacters(in: .whitespacesAndNewlines) == "" ||
            emaiL.text?.trimmingCharacters(in: .whitespacesAndNewlines) == "" ||
            password.text?.trimmingCharacters(in: .whitespacesAndNewlines) == "" {
            
            return "Please fill in all fields.".localized()
        }
        
        // Check if the password is secure
        let cleanedPassword = password.text!.trimmingCharacters(in: .whitespacesAndNewlines)
        
        if Utilities.isPasswordValid(cleanedPassword) == false {
            // Password isn't secure enough
            return "Use 8 characters(including special & a number)".localized()
        }
        
        return nil
    }
    @IBAction func signUpTapped(_ sender: Any) {
        
        // Validate the fields
        let error = validateFields()
        
        if error != nil {
            
            // There's something wrong with the fields, show error message
            showError(error!)
        }
        else {
            // Create cleaned versions of the data
            let Firstname = firstName.text!.trimmingCharacters(in: .whitespacesAndNewlines)
            let Lastname = lastName.text!.trimmingCharacters(in: .whitespacesAndNewlines)
            _ = emaiL.text!.trimmingCharacters(in: .whitespacesAndNewlines)
            _ = password.text!.trimmingCharacters(in: .whitespacesAndNewlines)
            // Create the user
            Auth.auth().createUser(withEmail: emaiL.text!, password: password.text!) { (result, err) in
                
                // Check for errors
                if err != nil {
                    
                    // There was an error creating the user
                    self.showError("Error creating user")
                }
                else {
                    
                    // User was created successfully, now store the first name and last name
                    let db = Firestore.firestore()
                    db.collection("users").document(result!.user.uid).setData(["firstname": Firstname,"lastname": Lastname ,"uid": result!.user.uid]){ (error) in
                        
                        if error != nil {
                            // Show error message
                            self.showError("Error saving user data")
                        }
                    }
                    
                    
                    // Transition to the home screen
                    self.transitionToHome()
                }
                
            }
            
            
            
        }
    }
    
    func showError(_ message:String) {
        
        errorLabel.text = message
        errorLabel.alpha = 1
    }
    
    func transitionToHome() {
        
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let vc = storyboard.instantiateViewController(withIdentifier: "onboardingScreen")
        vc.modalPresentationStyle = .overFullScreen
        self.present(vc, animated: true)
        
        
    }
    
}
