import java.util.Scanner;

public class Dansmattan {

	public static void main(String[] args) {
		
		// Create scanner
		
		Scanner scanner = new Scanner(System.in);
		
		// Get beats count

		System.out.println("Antal takter:");
		int beatsCount = scanner.nextInt();	
		
		// Get steps for all beats
		
		String[] beats = new String[beatsCount];
		
		for (int i = 0; i < beatsCount; i++) {
			System.out.println("Steg i takt " + (i + 1) + ":");
			String beat = scanner.next(); 
			beats[i] = beat;
		}
		
		// Find the best way
		
		int changes = 0;
		
		int fot1 = 2, fot2 = 3;
		
		for (int i = 0; i < beatsCount; i++) {
			String beat = beats[i];
			if (beat.length() > 1) {

				int index1 = indexOfStep(beat.substring(0, 1));
				int index2 = indexOfStep(beat.substring(1, 2));
				
				if (fot1 != index1 && fot2 != index1) {
					if (fot1 != index2) {
						fot1 = index1;
						fot2 = index2;
					} else {
						fot1 = index2;
						fot2 = index1;
					}
				}
				
			} else {
				int index = indexOfStep(beat);
				if (fot1 != index && fot2 != index) {
					fot1 = index;
					changes++;
				}
			}
		}

		// Print result
		
		System.out.println("Resultat: " + changes);
		
		// Close scanner
		
		scanner.close();
	}
	
	/*
	 * U = 1
	 * H = 2
	 * V = 3
	 * N = 4
	 */
	
	static int indexOfStep(String stepString) {
		String s = stepString.toUpperCase();
		if (s.equals("U")) {
			return 1;
		} else if (s.equals("H")) {
			return 2;
		} else if (s.equals("V")) {
			return 3;
		} else if (s.equals("N")) {
			return 4;
		} else {
			return 1;
		}
	}
}
