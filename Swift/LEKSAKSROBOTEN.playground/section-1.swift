// Playground - noun: a place where people can play

import UIKit

func isInstructionRotation(instruction: String) -> Bool {
	return instruction.toInt() == nil
}

//let instructions = ["4", "H", "2", "H", "6", "V", "2", "H", "2", "H", "6", "H", "1"]
let instructions = ["V", "5", "V", "V", "6"]
//let instructions = ["H", "10", "V", "3", "V"]

//let intructionCount = instructions.count

var positionX = 0
var positionY = 0
var rotation = 0

for instruction in instructions {
	if isInstructionRotation(instruction) {
		if instruction == "H" {
			++rotation
		} else {
			--rotation
		}
		if rotation == -1 {
			rotation = 3
		} else if rotation == 4 {
			rotation = 0
		}
	} else {
		let movment = instruction.toInt()!
		switch rotation {
		case 0:
			positionY -= movment
		case 1:
			positionX -= movment
		case 2:
			positionY += movment
		case 3:
			positionX += movment
		default:
			break
		}
	}
}

positionX
positionY

var newInstructions = ""

if positionY != 0 {
	if positionY > 0 {
		newInstructions += "V"
		
		newInstructions += String(positionY)
	} else if positionY < 0 {
		//newInstructions += "H"
		
		newInstructions += String(-positionY)
	}
}

if positionX != 0 {
	if positionX > 0 {
		newInstructions += "V"
		
		newInstructions += String(positionX)
	} else if positionX < 0 {
		newInstructions += "H"
		
		newInstructions += String(-positionX)
	}
}

newInstructions