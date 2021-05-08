//
//  WorkoutViewController.swift
//  GetFit
//
//  Created by iosdev on 14.4.2021.
//

import UIKit
import CardSlider


struct Item: CardSliderItem {
    var image: UIImage
    var rating: Int?
    var title: String
    var subtitle: String?
    var description: String?
}

class WorkoutViewController: UIViewController, CardSliderDataSource {
    
    //@IBOutlet var myButton: UIButton!
    
    var data = [Item]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        data.append(Item(image: UIImage(named:"Workout")!,
                         rating: nil,
                         title: "4 Day Barbell Only Workout".localized(),
                         subtitle: "Main Goal Build Muscle".localized(),
                         description: "Are you stuck without a squat rack and bench? This 4-day upper/lower split will show you exactly how to get strong, and add muscle with only a barbell at your disposal.".localized()))
        
        data.append(Item(image: UIImage(named:"Workout2")!,
                         rating: nil,
                         title: "Full Body Fat Loss Workout".localized(),
                         subtitle: "Lose Fat".localized(),
                         description: "There's a faster way to fat loss than the treadmill. These fat burning workouts are designed to help you start making progress with just your own body weight.".localized()))
        
        data.append(Item(image: UIImage(named:"Workout3")!,
                         rating: nil,
                         title: "12 Week Full Body Workout".localized(),
                         subtitle: "Build Muscle".localized(),
                         description: "A 12 week full body beginner workout routine designed to introduce you to a range of gym equipment and basic bodybuilding exercises in under 60 minutes.".localized()))
        data.append(Item(image: UIImage(named:"Workout4")!,
                         rating: nil,
                         title: "Workouts for Women: 2".localized(),
                         subtitle: "Lose Fat".localized(),
                         description: "No time to make it to the gym or don't have a gym membership? These 2 bodyweight circuits are exactly what you're looking for to help you get in shape!".localized()))
        data.append(Item(image: UIImage(named:"Workout5")!,
                         rating: nil,
                         title: "6 Week Fat Loss Workout".localized(),
                         subtitle: "Lose Fat".localized(),
                         description: "Kick off your summer shredding with a quick and intense program. This 6 week fat loss workout supersets resistance training with cardio for maximum workout intensity.".localized()))
        data.append(Item(image: UIImage(named:"Workout6")!,
                         rating: nil,
                         title: "8 Week Power Workout".localized(),
                         subtitle: "Increase Strength".localized(),
                         description: "Forget what you know about the squat, bench press, and deadlift. There's 3 new big lifts in town to help you transform your body and increase your strength.".localized()))
        
        let vc = CardSliderViewController.with(dataSource: self)
        
        vc.title = "Workout Programs".localized()
        
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
