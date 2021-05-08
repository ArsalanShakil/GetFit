//
//  GetFitUITests.swift
//  GetFitUITests
//
//  Created by iosdev on 13.4.2021.
//

import XCTest

// BEFORE YOUR RUN THE TESTS LOGOUT OF THE APP & PLEASE CHANGE YOUR SIMULATOR SETTINGS INORDER FOR THEM TO RUN CORRECTLY

// OPEN SIMULATOR IN THE TOP BAR MENU OPEN I/O > Keyboard > Uncheck/Disable the (Connect Hardware Keyboard)

// Enable it again once the tests are done since it disables your laptop keyboard to work on simulator :)

class GetFitUITests: XCTestCase {

    override func setUpWithError() throws {
        // Put setup code here. This method is called before the invocation of each test method in the class.

        // In UI tests it is usually best to stop immediately when a failure occurs.
        continueAfterFailure = false

        // In UI tests it’s important to set the initial state - such as interface orientation - required for your tests before they run. The setUp method is a good place to do this.
    }

    override func tearDownWithError() throws {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
    }

    func testswipe() throws {
        // UI tests must launch the application that they test.
        let app = XCUIApplication()
        app.launch()
        
        let signup = app.buttons["Signup?"]
        signup.tap()
        
        
        
        

  
    }

    func testlogin() throws {
        // UI tests must launch the application that they test.
        let app = XCUIApplication()
        app.launch()
        
        let login = app.buttons["Login"]
        login.tap()


    }
    
    func testsignup() throws {
        // UI tests must launch the application that they test.
        let app = XCUIApplication()
        app.launch()
        
        let swipe = app.buttons["Signup?"]
        swipe.tap()
        
        let signup = app.buttons["Signup"]
        signup.tap()


    }
    
    func testbetweenSignupAndLoginPages() throws {
        // UI tests must launch the application that they test.
        let app = XCUIApplication()
        app.launch()
        
        let swipe = app.buttons["signup"]
        swipe.tap()
        
        let login = app.buttons["login"]
        login.tap()


    }
    
    func testinputEmail() throws {
        // UI tests must launch the application that they test.
        let app = XCUIApplication()
        app.launch()
        
        let usernameTextField = app.textFields["Email"]
               usernameTextField.tap()
               usernameTextField.typeText("abc@gmail.com")


    }
    
    func testSignupfirstname() throws {
        // UI tests must launch the application that they test.
        let app = XCUIApplication()
        app.launch()
        
        let swipe = app.buttons["Signup?"]
        swipe.tap()
        
        let usernameTextField = app.textFields["firstname"]
               usernameTextField.tap()
               usernameTextField.typeText("darshil")
    }
    
    func testSignupsecondname() throws {
        // UI tests must launch the application that they test.
        let app = XCUIApplication()
        app.launch()
        
        let swipe = app.buttons["Signup?"]
        swipe.tap()
        
        let secondnameTextField = app.textFields["secondname"]
        secondnameTextField.tap()
        secondnameTextField.typeText("darshil")
       
        
        
        let signup = app.buttons["Signup"]
        signup.tap()
        
    }

    
    func testSignupemail() throws {
        // UI tests must launch the application that they test.
        let app = XCUIApplication()
        app.launch()
        
        let swipe = app.buttons["Signup?"]
        swipe.tap()
        
        let emailTextField = app.textFields["email"]
        emailTextField.tap()
        emailTextField.typeText("darshil@123.com")
        
        
        let signup = app.buttons["Signup"]
        signup.tap()
        
    }
    
    func testLogin() throws {
        // UI tests must launch the application that they test.
        let app = XCUIApplication()
        app.launch()
        let password = app.secureTextFields["Password"]
        
        let emailTextField = app.textFields["Email"]
        emailTextField.tap()
        emailTextField.typeText("arsalanshakil@gmail.com")
        
        
        password.tap()
        password.typeText("Abc@1234")
    
        
        let login = app.buttons["loginbtn"]
        login.tap()
        
        let profile = app.buttons["profile"]
        profile.tap()
        
        let logout = app.buttons["logout"]
        logout.tap()
        
    }
    
    // Please change the user credentails before running this test as you can not sign Up again with the same user info
    func testSignup() throws {
        // UI tests must launch the application that they test.
        let app = XCUIApplication()
        app.launch()
        
        let swipe = app.buttons["Signup?"]
        swipe.tap()
        
        let secondnameTextField = app.textFields["secondname"]
        let emailTextField = app.textFields["email"]
        let passwordTextField = app.secureTextFields["password"]
        let firstTextField = app.textFields["firstname"]
        firstTextField.tap()
        firstTextField.typeText("ziang") //change here
        
     
        secondnameTextField.tap()
        secondnameTextField.typeText("zhao") // change here
        
        emailTextField.tap()
        emailTextField.typeText("1111095221@qq.com") //change here
        
     
        passwordTextField.tap()
        passwordTextField.typeText("ziang@1234") //change here
    
        let signup = app.buttons["signupbtn"]
        signup.tap()
        
        app.swipeLeft()
        app.swipeLeft()
        app.swipeLeft()
        
        let skip = app.buttons["skip"]
        skip.tap()
        
        let profile = app.buttons["profile"]
        profile.tap()
        
        let logout = app.buttons["logout"]
        logout.tap()

    }
    
    func testnavigationbar() throws {
        // UI tests must launch the application that they test.
        let app = XCUIApplication()
        app.launch()
        let password = app.secureTextFields["Password"]
        
        let emailTextField = app.textFields["Email"]
        emailTextField.tap()
        emailTextField.typeText("196663192@qq.com")
        
        
        password.tap()
        password.typeText("ziang@1234")
    
        
        let login = app.buttons["loginbtn"]
        login.tap()
        
       
        let meal = app.buttons["meals"]
        meal.tap()
        
        let workout = app.buttons["workout"]
        workout.tap()
        
        let profile = app.buttons["profile"]
        profile.tap()
        
        let logout = app.buttons["logout"]
        logout.tap()
        
    }
    
    func testworkoutpage() throws {
        // UI tests must launch the application that they test.
        let app = XCUIApplication()
        app.launch()
        let password = app.secureTextFields["Password"]
        
        let emailTextField = app.textFields["Email"]
        emailTextField.tap()
        emailTextField.typeText("196663192@qq.com")
        
        
        password.tap()
        password.typeText("ziang@1234")
    
        
        let login = app.buttons["loginbtn"]
        login.tap()
        
        let meal = app.buttons["meals"]
        meal.tap()

        let workout = app.buttons["workout"]
        workout.tap()
        
        app.swipeRight()
        app.swipeRight()
        app.swipeRight()
        app.swipeRight()
        app.swipeRight()


        
        let profile = app.buttons["profile"]
        profile.tap()
        
        let logout = app.buttons["logout"]
        logout.tap()
        
    }
    
    func testmealpage() throws {
        // UI tests must launch the application that they test.
        let app = XCUIApplication()
        app.launch()
        let password = app.secureTextFields["Password"]
        
        let emailTextField = app.textFields["Email"]
        emailTextField.tap()
        emailTextField.typeText("196663192@qq.com")
        
        
        password.tap()
        password.typeText("ziang@1234")
    
        
        let login = app.buttons["loginbtn"]
        login.tap()
        
        let meal = app.buttons["meals"]
        meal.tap()

        
        app.swipeRight()
        app.swipeRight()
        app.swipeRight()
        app.swipeRight()
        app.swipeRight()


        
        let profile = app.buttons["profile"]
        profile.tap()
        
        let logout = app.buttons["logout"]
        logout.tap()
        
    }
    
    




    func testLaunchPerformance() throws {
        if #available(macOS 10.15, iOS 13.0, tvOS 13.0, *) {
            // This measures how long it takes to launch your application.
            measure(metrics: [XCTApplicationLaunchMetric()]) {
                XCUIApplication().launch()
            }
        }
    }
}
