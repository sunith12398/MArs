# MArs
LIGHT DOSE
Q1.
I learned how to use basic Linux commands like `mkdir`, `touch`, `mv`, `grep`, `top`, and `shutdown` to manage files, check system info, and do tasks like renaming files and scheduling shutdowns. My method was simple: I tried out each command step-by-step and used online guides or `man` pages whenever I wasn’t sure about the options. The hardest part was remembering the correct flags and making sense of outputs from commands like `top`. Even though these were small issues, this task helped me become more confident and quicker when working with the Linux terminal.

Q2
When working on the Bash script for the rover system check, I broke the job into smaller steps: generating random battery percentages, checking if the battery was below a set level, testing network connection with `ping`, and logging messages. At first, Bash syntax, handling exit statuses, and edge cases like boundary values were tough to understand. I took my time, testing the script part by part and using `echo` for debugging. With more practice, I got better at scripting and learned how to deal with its quirks.

MEDIUM DOSE
Q3  
I adjusted the rover’s position by shifting the x-coordinate to account for the camera’s 55 cm offset, making sure it aligned properly with the marker. The challenge was figuring out how the camera’s offset affected navigation and getting the new position calculated correctly. After making some tweaks, I managed to solve the issue and ensured the rover could turn 360 degrees accurately.

Q4
This task involved using a dictionary to translate Morse code and splitting the input to handle spaces between words. The tricky part was managing word separation with spaces while translating quickly and accurately. Once I figured out how to map Morse code to letters and used simple string functions like `split()` and `join()`, the process became straightforward.

Q5
For this, I decrypted a reverse Caesar cipher using basic string operations and ASCII functions like `ord` and `chr`. The main challenge was making sure the shift went smoothly and wrapped around when letters went before 'A'. Using modulo 26 solved this problem, and I was able to reverse the encryption step by step.

Q6 
In this task, I applied filters like moving average and median to reduce noise in sensor data and evaluated their performance by calculating variance. Setting up the sliding window technique for the filters was a bit tough at first, but once it was done, combining them into a hybrid filter worked really well. The variance calculation helped pick the best method for stable sensor data processing.

Q7
I learned about how quaternions represent 3D rotations and avoid the gimbal lock problem that Euler angles have. Converting angles to quaternions involved using a formula, which was confusing in the beginning. But once I practiced and remembered to convert angles to radians, it got easier. Quaternions are great for robotics and 3D applications.
1. Convert Euler Angles (Roll, Pitch, Yaw) to Quaternion:

Given the Euler angles:
	•	Roll (ϕ): Rotation about the x-axis
	•	Pitch (θ): Rotation about the y-axis
	•	Yaw (ψ): Rotation about the z-axis

The quaternion components can be computed as:

q₀ = cos(ϕ/2) * cos(θ/2) * cos(ψ/2) + sin(ϕ/2) * sin(θ/2) * sin(ψ/2)

q₁ = sin(ϕ/2) * cos(θ/2) * cos(ψ/2) - cos(ϕ/2) * sin(θ/2) * sin(ψ/2)

q₂ = cos(ϕ/2) * sin(θ/2) * cos(ψ/2) + sin(ϕ/2) * cos(θ/2) * sin(ψ/2)

q₃ = cos(ϕ/2) * cos(θ/2) * sin(ψ/2) - sin(ϕ/2) * sin(θ/2) * cos(ψ/2)

Where:
	•	ϕ is the roll angle
	•	θ is the pitch angle
	•	ψ is the yaw angle

These equations convert Euler angles (roll, pitch, yaw) into a quaternion q = (q₀, q₁, q₂, q₃).


HARD DOSE
Q8
In this task, I represented a 2D arena grid and used BFS to find the shortest path while dodging obstacles. Parsing the obstacle data from a `.txt` file and mapping it correctly to the grid was the first challenge. Debugging BFS to make sure positions weren’t revisited and obstacles were avoided was also tricky. In the end, I learned how pathfinding algorithms work and how to manage grid boundaries.

Q9
I learned how to detect objects and calculate distances using the pinhole camera model. My method involved processing the image, detecting the arrow, and using a formula to find the distance based on the camera specs. The hardest part was figuring out the focal length and making sure the measurements were accurate. Debugging the contour detection was also challenging, but overall, I improved my understanding of image analysis.
Formula for Distance Calculation:
{Distance} = {Real Arrow Width} *{Focal Length}}/{Perceived Arrow Width}



Q10
In this task, we used Behavior Trees (BT) to model decision-making for the Mars rover. Sequence nodes handled tasks one by one, while Fallback nodes checked priorities like returning to base if the battery was critically low or saving power if it was low but manageable. Fallback nodes made sure the rover reacted to urgent issues first, and Sequence nodes kept everything else organized. Structuring the BT logic and balancing flexibility with robustness were challenging, but in the end, this approach made the system easier to maintain and update compared to if-else conditions.
