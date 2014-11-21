package LeksaksRoboten;

import java.util.ArrayList;
import java.util.Scanner;

public class LeksaksRoboten {

	public LeksaksRoboten(){
		Scanner scanner = new Scanner(System.in);
		
		String input = null;
		
		System.out.print("Antal instruktioner ? ");
		int instructions = scanner.nextInt();
		
		float xGoal = 0, yGoal = 0;
		int dir = 0; // 0 = up, 1 = left, 2 = down, 3 = right
		
		for(int i = 0; i < instructions; i++){
			System.out.print("Instruktion" + (i + 1) + "?");
			String instruction = scanner.next();
			
			if(instruction.equals("H")){
				dir--;
				if(dir < 0){
					dir = 3;
				}
				continue;
			}
			else if(instruction.equals("V")){
				dir++;
				if(dir > 3){
					dir = 0;
				}
				continue;
			}
			
			
			int steps = Integer.parseInt(instruction);
			if(dir == 0){
				 yGoal += steps;
			}
			if(dir == 1){
				xGoal += -steps;
			}
			if(dir == 2){
				yGoal += -steps;
			}
			if(dir == 3){
				xGoal += steps;
			}
		}
		
		//Starts simulation
		
		ArrayList<String> steps = new ArrayList<String>();

		float xPos = 0, yPos = 0;
		
		dir = 0; //resets the direction.
	
		System.out.println("xGoal = " + xGoal + ", yGoal = " + yGoal);
		
		boolean followXFirstTime = false;
		
		//Does the first rotation
		if(yGoal < 0){
			if(xGoal < 0){
				steps.add("V");
				dir = 1;
			}
			else if(xGoal > 0){
				steps.add("H");
				dir = 3;
			}
			followXFirstTime = true;
		}
		else if(yGoal > 0){
			followXFirstTime = false;
		}
	
		if(followXFirstTime){
			steps.add("" + (int)(Math.abs(xGoal)));
			if(yGoal > 0){
				if(dir == 1){
					steps.add("H");
				}
				if(dir == 3){
					steps.add("V");	
				}
				steps.add("" + (int)(Math.abs(yGoal)));
			}
			if(yGoal < 0){
				if(dir == 1){
					steps.add("V");
				}
				if(dir == 3){
					steps.add("H");	
				}
				steps.add("" + (int)(Math.abs(yGoal)));
			}
		}
		
		else if(!followXFirstTime){
			steps.add("" + (int)(Math.abs(yGoal)));
			if(xGoal > 0){
				steps.add("H");
			}
			if(xGoal < 0){
				steps.add("V");
			}
			steps.add("" + (int)(Math.abs(xGoal)));
		}
		
		System.out.println("Done with " + steps.size() + " steps");
		
		for(String s : steps){
			System.out.println(s);
		}
		
		scanner.close();
	}
	
	public static void main(String[] args){
		new LeksaksRoboten();	
	}
}
