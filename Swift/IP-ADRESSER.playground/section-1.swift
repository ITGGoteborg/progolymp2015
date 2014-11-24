
import UIKit

func isValidIP(ip: NSString) -> Bool {
	let components = ip.componentsSeparatedByString(".")
	for component in components as [String] {
		if let intValue = component.toInt() {
			if countElements(String(intValue)) == countElements(component) {
				if intValue > 255 {
					return false
				}
			} else {
				return false
			}
		} else {
			return false
		}
	}
	return true
}

var numbers = "20142014" as NSString
var found = [] as [String]

for var i = 0; i < 300; ++i {
	var test = numbers
	for var p = 0; p < 3; ++p {
		let rN1 = Int(arc4random_uniform(UInt32(test.length)))
		
		let part1 = test.substringWithRange(NSMakeRange(0, rN1))
		let part2 = test.substringWithRange(NSMakeRange(rN1, test.length - rN1))
		test = part1 + "." + part2
	}
	if find(found, test) == nil {
		if isValidIP(test) {
			found.append(test)
		}
	}
}

found.count

