Student Portal Management System (C++ with Qt)

Welcome to the Student Portal Management System, a desktop application developed using C++ and the Qt framework. This application provides a secure and efficient way for students to manage their academic and personal information, enroll in courses, calculate CGPA, and handle payments and parking permits.

✅ Features Implemented
1️⃣ Secure Login & Signup
Password Hashing: Passwords are securely hashed using cryptographic algorithms before storage.

Password Masking: Passwords are masked during input to enhance security.

2️⃣ Student Information Submission
Students can submit and update their personal details, including:

Signup Fields:
Username
Password
Parent’s Name
Birth Date
Nationality
Blood Group
ID Number
Photo Upload

3️⃣ Photo Upload & CSV-based Data Storage
Photo Upload: Students can upload their profile pictures, which are stored locally.

CSV-based Data Storage: All student data is stored in CSV files for easy management and export.

4️⃣ Dashboard
View Student Information: Students can view their submitted information in a user-friendly dashboard.

Edit Student Information: Allows students to update their details as needed.

5️⃣ CGPA Calculator
A built-in CGPA calculator helps students calculate their Cumulative Grade Point Average based on their grades.

6️⃣ Course Enrollment & Analysis
Course Enrollment: Students can enroll in courses for the upcoming semester.

Course Analysis: Provides insights into course load, prerequisites, and performance trends.

7️⃣ Payment & Parking Management
Payment Management: Students can view and pay their tuition fees, library fines, and other charges.

Parking Management: Allows students to register for parking permits and manage their parking details.

8️⃣ Logout Functionality
Secure logout functionality ensures that the user session is properly terminated, protecting user data.
Functionality

📌 Project File Structure
/StudentPortal
│── main.cpp
│── loginwindow.h
│── loginwindow.cpp
│── dashboard.h
│── dashboard.cpp
│── cgpa_calculator.h
│── cgpa_calculator.cpp
│── course_management.h
│── course_management.cpp
│── payment_parking.h
│── payment_parking.cpp
│── users.csv  (Data Storage)

🚀 Getting Started
Prerequisites
Qt Framework (version 5 or higher)

C++ Compiler (GCC)

CMake (for building the project)

Installation
Clone the repository:

bash
Copy
git clone https://github.com/tushar1095/cse_299-Project
Navigate to the project directory:

bash
Copy
cd student-portal-management-qt
Build the project using CMake:

bash
Copy
mkdir build
cd build
cmake ..
make
Run the application:

bash
Copy
./StudentPortalManagement


🛠️ Technologies Used
Programming Language: C++

Framework: Qt (for GUI and application logic)

Data Storage: CSV files

Security: Cryptographic hashing for passwords

Thank you for using the Student Portal Management System! We hope it makes your academic journey smoother and more organized. 
