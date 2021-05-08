//
//  ProfileViewController.swift
//  GetFit
//
//  Created by iosdev on 14.4.2021.
//

import Foundation
import UIKit
import Firebase
import FirebaseStorage

class ProfileViewController: UIViewController {
    @IBOutlet weak var Firstname: UILabel!
    @IBOutlet weak var Lastname: UILabel!
    @IBOutlet weak var Email: UILabel!
    
    @IBOutlet weak var logoutButtonLabel: UIButton!
    let email = Auth.auth().currentUser!.email
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.Email.text = email
        
        logoutButtonLabel.setTitle("Logout".localized(), for: .normal)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated) // call super
        
        getName { (name) in
            if let name = name {
                self.Firstname.text = name
                print("great success")
            }
        }
        getlastName { (lastname) in
            if let lastname = lastname {
                self.Lastname.text = lastname
                print("great success")
            }
        }
    }
    func getName(completion: @escaping (_ name: String?) -> Void) {
        guard let uid = Auth.auth().currentUser?.uid else {
            completion(nil) // user is not logged in; return nil
            return
        }
        
        Firestore.firestore().collection("users").document(uid).getDocument { (docSnapshot, error) in
            if let doc = docSnapshot {
                if let name = doc.get("firstname") as? String {
                    completion(name) // success; return name
                } else {
                    print("error getting field")
                    completion(nil) // error getting field; return nil
                }
            } else {
                if let error = error {
                    print(error)
                }
                completion(nil) // error getting document; return nil
            }
        }
    }
    
    func getlastName(completion: @escaping (_ name: String?) -> Void) {
        guard let uid = Auth.auth().currentUser?.uid else {
            completion(nil) // user is not logged in; return nil
            return
        }
        
        Firestore.firestore().collection("users").document(uid).getDocument { (docSnapshot, error) in
            if let doc = docSnapshot {
                if let lastname = doc.get("lastname") as? String {
                    completion(lastname) // success; return name
                } else {
                    print("error getting field")
                    completion(nil) // error getting field; return nil
                }
            } else {
                if let error = error {
                    print(error)
                }
                completion(nil) // error getting document; return nil
            }
        }
    }
    
    
    @IBAction func Logout(_ sender: Any) {
        try! Auth.auth().signOut()
        self.transitionToHome()
    }
    
    func transitionToHome() {
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let vc = storyboard.instantiateViewController(withIdentifier: "login")
        vc.modalPresentationStyle = .overFullScreen
        self.present(vc, animated: true)
    }
}
