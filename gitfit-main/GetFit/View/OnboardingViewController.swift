
import UIKit
import paper_onboarding

class OnboardingViewController: UIViewController {
    
    @IBOutlet var skipButton: UIButton!
    
    fileprivate let items = [
        OnboardingItemInfo(informationImage: UIImage(named:"Run")!,
                           title: "Welcome".localized(),
                           description: "The best health assistant for all your needs.".localized(),
                           pageIcon:
                            UIImage(named:"workout-1")!,
                           color: UIColor(red: 0.93, green: 0.78, blue: 0.29, alpha: 1.00),
                           titleColor: UIColor.white, descriptionColor: UIColor.white, titleFont: titleFont, descriptionFont: descriptionFont),
        
        OnboardingItemInfo(informationImage: UIImage(named:"Meals")!,
                           title: "Diets".localized(),
                           description: "Browse through our collection of meals.".localized(),
                           pageIcon: UIImage(named:"food")!,
                           color: UIColor(red: 0.86, green: 0.63, blue: 0.59, alpha: 1.00),
                           titleColor: UIColor.white, descriptionColor: UIColor.white, titleFont: titleFont, descriptionFont: descriptionFont),
        
        OnboardingItemInfo(informationImage: UIImage(named:"Health")!,
                           title: "Progress".localized(),
                           description: "Track your progress to continue your fitness journey.".localized(),
                           pageIcon: UIImage(named:"healthy")!,
                           color: UIColor(red: 0.27, green: 0.29, blue: 0.96, alpha: 1.00),
                           titleColor: UIColor.white, descriptionColor: UIColor.white, titleFont: titleFont, descriptionFont: descriptionFont),
        
    ]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        skipButton.isHidden = true
        
        setupPaperOnboardingView()
        
        view.bringSubviewToFront(skipButton)
    }
    
    private func setupPaperOnboardingView() {
        let onboarding = PaperOnboarding()
        onboarding.delegate = self
        onboarding.dataSource = self
        onboarding.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(onboarding)
        
        // Add constraints
        for attribute: NSLayoutConstraint.Attribute in [.left, .right, .top, .bottom] {
            let constraint = NSLayoutConstraint(item: onboarding,
                                                attribute: attribute,
                                                relatedBy: .equal,
                                                toItem: view,
                                                attribute: attribute,
                                                multiplier: 1,
                                                constant: 0)
            view.addConstraint(constraint)
        }
    }
}

// MARK: Actions

extension OnboardingViewController {
    
    @IBAction func skipButtonTapped(_: UIButton) {
        print(#function)
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let vc = storyboard.instantiateViewController(identifier: "feedscreen")
        vc.modalPresentationStyle = .overFullScreen
        present(vc, animated: true)
    }
}

// MARK: PaperOnboardingDelegate

extension OnboardingViewController: PaperOnboardingDelegate {
    
    func onboardingWillTransitonToIndex(_ index: Int) {
        skipButton.isHidden = index == 2 ? false : true
    }
    
    func onboardingConfigurationItem(_ item: OnboardingContentViewItem, index: Int) {
        
        //item.titleCenterConstraint?.constant = 100
        //item.descriptionCenterConstraint?.constant = 100
        
        // configure item
        
        //item.titleLabel?.backgroundColor = .redColor()
        //item.descriptionLabel?.backgroundColor = .redColor()
        //item.imageView = ...
    }
}

// MARK: PaperOnboardingDataSource

extension OnboardingViewController: PaperOnboardingDataSource {
    
    func onboardingItem(at index: Int) -> OnboardingItemInfo {
        return items[index]
    }
    
    func onboardingItemsCount() -> Int {
        return 3
    }
    

}


//MARK: Constants
private extension OnboardingViewController {
    
    static let titleFont = UIFont(name: "Nunito-Bold", size: 36.0) ?? UIFont.boldSystemFont(ofSize: 36.0)
    static let descriptionFont = UIFont(name: "OpenSans-Regular", size: 14.0) ?? UIFont.systemFont(ofSize: 14.0)
}

