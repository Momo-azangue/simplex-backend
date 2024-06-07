Overview
This project provides a PERT (Program Evaluation Review Technique) calculator to manage tasks and their dependencies. 
It helps to determine the earliest and latest start and finish dates for tasks,
calculates margins, and identifies the critical path in a project.

Technologies Used


C for backend calculations.
Node.js with Express for the server.
React.js for the frontend.




Prerequisites
Node.js and npm installed.
GCC for compiling C programs.
Getting Started
Backend Setup




Clone the repository:

git clone https://github.com/Momo-azangue/simplex-backend.git
cd simplex-backend



Install dependencies:


npm install
Compile the C program:

bash
Copier le code
gcc -o pert src/pert.c
Start the backend server:

node server.js
Frontend Setup


Navigate to the frontend directory:




cd frontend



Install frontend dependencies:


npm install


Start the frontend application:


npm run dev

Usage


Add Tasks:

Navigate to http://localhost:3001 in your browser.

Enter the task name and duration.

Click "Add Task" to add it to the project.

Add Relations:

Enter the dependent task and its predecessors.
Click "Add Relation" to establish dependencies between tasks.
Calculate Dates:

Click "Calculate Dates" to compute the earliest and latest start and finish dates, margins, and identify the critical path.


Example


Input File (input.txt):

4
0 Fictive 0
1 A 20
2 B 30
3 C 10
3
3 1
3 2
2 1
Output File (output.txt):

0 Fictive 0 0 0 0 0
1 A 20 0 20 0 0
2 B 30 20 50 0 0
3 C 10 50 60 0 0

Troubleshooting
Ensure the C program is compiled correctly and executable (gcc -o pert src/pert.c).
Check if the backend server is running (node server.js).
Verify the frontend app is running (npm start in the frontend directory).
Contributing

Fork the repository.
Create your feature branch (git checkout -b feature/AmazingFeature).
Commit your changes (git commit -m 'Add some AmazingFeature').
Push to the branch (git push origin feature/AmazingFeature).
Open a pull request.



