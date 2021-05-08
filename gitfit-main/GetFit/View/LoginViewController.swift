//
//  LoginViewController.swift
//  GetFit
//
//  Created by iosdev on 23.4.2021.
//

import UIKit
import FirebaseAuth
import Firebase

class LoginViewController: UIViewController {
    
    @IBOutlet weak var email: UITextField!
    @IBOutlet weak var password: UITextField!
    @IBOutlet weak var loginButton: UIButton!
    @IBOutlet weak var errorLabel: UILabel!
    @IBOutlet weak var signUpButton: UIButton!
    @IBOutlet weak var loginLabel: UILabel!
    @IBOutlet weak var loginButtonLabel: UIButton!
    override func viewDidLoad() {
        super.viewDidLoad()
        errorLabel.alpha = 0
        
        loginLabel.text="Login to GetFit".localized()
        signUpButton.setTitle("Signup?".localized(), for: .normal)
        loginButton.setTitle("Login".localized(), for: .normal)
        
    }
    //UN COMMENT THIS ONCE THE TESTING IS DONE
    
    // FOR SAVE USER LOGIN DATA
    override func viewDidAppear(_ animated: Bool) {
        checkuserInfo()
    }
    func checkuserInfo(){
        if Auth.auth().currentUser != nil {
            print{Auth.auth().currentUser?.uid}
            let storyboard = UIStoryboard(name: "Main", bundle: nil)
            let vc = storyboard.instantiateViewController(identifier: "feedscreen")
            vc.modalPresentationStyle = .overFullScreen
            present(vc, animated: true)
        }
    }
    func validateFields() -> String? {
        
        // Check that all fields are filled in
        if  email.text?.trimmingCharacters(in: .whitespacesAndNewlines) == "" ||
                password.text?.trimmingCharacters(in: .whitespacesAndNewlines) == "" {
            
            return "Please fill in all fields.".localized()
        }
        
        return nil
    }
    
    func showError(_ message:String) {
        errorLabel.text = message
        errorLabel.alpha = 1
    }
    @IBAction func loginTapped(_ sender: Any) {
        
        let error = validateFields()
        
        if error != nil {
            
            // There's something wrong with the fields, show error message
            showError(error!)
        } else {
            
            _ = email.text!.trimmingCharacters(in: .whitespacesAndNewlines)
            _ = password.text!.trimmingCharacters(in: .whitespacesAndNewlines)
            
            // Signing in the user
            Auth.auth().signIn(withEmail: email.text!, password: password.text!) { (result, error) in
                
                if error == nil {
                    // Couldn't sign in
                    let storyboard = UIStoryboard(name: "Main", bundle: nil)
                    let vc = storyboard.instantiateViewController(identifier: "feedscreen")
                    vc.modalPresentationStyle = .overFullScreen
                    self.present(vc, animated: true)
                    
                }
                else {
                    self.showError("Wrong Username or Password".localized())
                }
            }
        }
    }
}
