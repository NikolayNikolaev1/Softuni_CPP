/*
Write a program, make a Class Student.
For given numbers the program should filter the students by MINIMUM VOTE.
If the students vote is greater or equal to the MINIMUM VOTE,
the program should give information.
If the VOTE is lower than the filtered the program should NOT give information.
*/
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct StudentInfo
{
	string name;
	string surname;
	int age;
	double votes;
};

// Class Student with name, surname, age and votes.
class Student
{
private:
	string name;
	string surname;
	int age;
	double votes;

public:
	Student(string name, string surname, int age, double votes)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->votes = votes;
	}

	double getVotes() { return this->votes; }

	string toString()
	{
		ostringstream outputStream;

		outputStream << "Name -> " << this->name << " " << this->surname << endl
			<< "Age -> " << this->age << endl
			<< "Votes -> " << this->votes;

		return outputStream.str();
	}

};

typedef vector<Student> Students;

Students filterStudents(Students students, double minVote);
void printStudentsInfo(Students students);
StudentInfo readStudentInfo();

void filterStudentsByMinVote()
{
	Students students;
	int studentsCount;
	cout << "How many students you want to input?" << endl;
	cin >> studentsCount;

	while (studentsCount--)
	{
		// Reads student info from input, creates student and adds him to studen vector until studentCount gets to 0.
		StudentInfo studentInfo = readStudentInfo();
		Student student = Student(studentInfo.name, studentInfo.surname, studentInfo.age, studentInfo.votes);
		students.push_back(student);
	}

	double minVote;
	cout << "Which is the minimal vote that you would like to filter?" << endl;
	cin >> minVote;

	students = filterStudents(students, minVote);

	cout << "The students with MIN vote -> " << minVote << " are:" << endl;
	printStudentsInfo(students);
}

// Filters students with votes equal or more than the minVote and returns the new filtered students vector.
Students filterStudents(Students students, double minVote)
{
	Students filteredStudents;

	for (Student student : students)
	{
		if (student.getVotes() >= minVote)
		{
			filteredStudents.push_back(student);
		}
	}

	return filteredStudents;
}

// Prints student info.
void printStudentsInfo(Students students)
{
	for (Student student : students)
	{
		cout << student.toString() << endl;
	}
}

// Reads name, surname age and votes for student from input and returns StudentInfo struct with the properties.
StudentInfo readStudentInfo()
{
	string name, surname;
	int age;
	double votes;

	cout << "Enter name: ";
	cin >> name;
	cout << "Enter surname: ";
	cin >> surname;
	cout << "Enter age: ";
	cin >> age;
	cout << "Enter vote (the vote can be with decimal point): ";
	cin >> votes;

	return StudentInfo
	{
		name = name,
		surname = surname,
		age = age,
		votes = votes
	};
}