//
//  WorkoutViewController.swift
//  GetFit
//
//  Created by iosdev on 14.4.2021.
//

import UIKit
import CardSlider


struct Single: CardSliderItem {
    var image: UIImage
    var rating: Int?
    var title: String
    var subtitle: String?
    var description: String?
}

class MealsViewController: UIViewController, CardSliderDataSource {
    
    //@IBOutlet var myButton: UIButton!
    
    var data = [Single]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        data.append(Single(image: UIImage(named:"Food1")!,
                           rating: nil,
                           title: "7-Day Mediterranean Meal Plan".localized(),
                           subtitle: "1,200 Calories".localized(),
                           description: "Recognized as one of the healthiest and most delicious ways to eat, the Mediterranean diet is easy to follow with this 7-day meal plan.".localized()))
        
        data.append(Single(image: UIImage(named:"Food2")!,
                           rating: nil,
                           title: "3-Day Diabetes Meal Plan".localized(),
                           subtitle: "1,300 Calories".localized(),
                           description: "Quick and delicious spring meals to help take the guesswork out of healthy eating for diabetes.".localized()))
        
        data.append(Single(image: UIImage(named:"Food3")!,
                           rating: nil,
                           title: "Weight-Loss Meal Plan".localized(),
                           subtitle: "1,200 Calories".localized(),
                           description: "The season's most delicious foods come together for a week of healthy meals, snacks and meal-prep ideas, geared to help you jump-start a healthy weight loss of 1 to 2 pounds per week.".localized()))
        data.append(Single(image: UIImage(named:"food4")!,
                           rating: nil,
                           title: "7-Day Vegetarian Meal Plan".localized(),
                           subtitle: "1,200 Calories".localized(),
                           description: "Whether you already follow a vegetarian diet or are just looking to go meatless sometimes, this 7-day vegetarian meal plan makes it easy to eat meat-free and lose weight. Eating more plant-based foods is a great way to boost your health. A vegetarian diet has been shown to reduce your risk of heart disease, type-2 diabetes and even certain types of cancer.".localized()))
        data.append(Single(image: UIImage(named:"food5")!,
                           rating: nil,
                           title: "7-Day Anti-Inflammatory Diet Plan".localized(),
                           subtitle: "1,200 Calories".localized(),
                           description: "In this healthy 1,200-calorie meal plan, the principles of an anti-inflammatory diet come together for a week of delicious, wholesome meals and snacks, plus meal-prep tips to set you up for a successful week ahead.".localized()))
        data.append(Single(image: UIImage(named:"food6")!,
                           rating: nil,
                           title: "Clean-Eating Meal Plan for Spring".localized(),
                           subtitle: "1,100 Calories".localized(),
                           description: "Eating clean is how we do things here at EatingWell—it's a simple, healthy approach to eating that focuses on foods that do the body good, while limiting the not-so-helpful items. In this clean-eating meal plan for spring, you'll find nutrient-rich foods like fruits and veggies, lean protein, whole grains and healthy fats and limited amounts of processed foods, refined grains, salt, added sugar and alcohol. ".localized()))
        
        let vc = CardSliderViewController.with(dataSource: self)
        
        vc.title = "Meals".localized()
        
        vc.modalPresentationStyle = .overCurrentContext
        present(vc,animated: true)
        
        
    }
    
    
    
    func item(for index: Int) -> CardSliderItem {
        return data[index]
    }
    
    func numberOfItems() -> Int {
        return data.count
    }
    
    
    
    
    
    
    
    
}
