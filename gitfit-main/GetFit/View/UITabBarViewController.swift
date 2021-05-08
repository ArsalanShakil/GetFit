//
//  UITabBarViewController.swift
//  GetFit
//
//  Created by iosdev on 13.4.2021.
//

import UIKit

class UITabBarViewController: UITabBarController {
    
    @IBOutlet weak var TabBar: UITabBar!
    override func viewDidLoad() {
        super.viewDidLoad()
        TabBar.unselectedItemTintColor = UIColor.black
        // Do any additional setup after loading the view.
    }

    
}
