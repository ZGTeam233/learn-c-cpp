#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int checkLevel() {
	int grade;
	cout << "\n=== CHEAK LEVEL ===\n";
	cout << "Enter your grade (0-100): ";
	cin >> grade;
	if (grade > 100 || grade < 0) {
		return 1; // 带错误退出函数
	}
	switch (grade / 10) {
	case 10:
	case 9:
		cout << "Grade level: A, outstanding\n";
		break;
	case 8:
		cout << "Grade level: B, exceeded expectations\n";
		break;
	case 7:
		cout << "Grade level: C, accept\n";
		break;
	case 6:
		cout << "Grade level: D, poor\n";
		break;
	default:
		cout << "Grade level: E, dreadful\n";
		break;
	}
	return 0; // 正常退出函数
}

int checkScholarship() {
	int grade;
	char isStuLeader;
	char isExcellentVolunteer;
	cout << "\n=== CHEAK SCHOLARSHIP ===\n";

	cout << "Enter your grade (0-100): ";
	cin >> grade;
	if (grade > 100 || grade < 0) {
		return 1; // 带错误退出函数
	}

	cout << "Have you ever been student leader? (Y/N): ";
	cin >> isStuLeader;
	isStuLeader = toupper(isStuLeader);
	if (isStuLeader != 'Y' && isStuLeader != 'N') {
		return 2; // 带错误退出函数
	}

	
	cout << "Have you ever attended the excellent volunteer activities? (Y/N): ";
	cin >> isExcellentVolunteer;
	isExcellentVolunteer = toupper(isExcellentVolunteer);
	if (isExcellentVolunteer != 'Y' && isExcellentVolunteer != 'N') {
		return 2; // 带错误退出函数
	}

	cout << "\n--- SCHOLARSHIP RESULT ---\n";
	cout << "Grade: " << grade << "\n";
	cout << "Student leader: " << (isStuLeader == 'Y' ? "Yes" : "No") << "\n";
	cout << "Excellent volunteer: " << (isExcellentVolunteer == 'Y' ? "Yes" : "No") << "\n";
	
	bool isEligible = false;
	string scholarType = "";

	if (grade >= 90) {
		isEligible = true;
		scholarType = "Excellent Grade"; // 成绩优异
	} else if (grade >= 80 && isStuLeader == 'Y') {
		isEligible = true;
		scholarType = "Student Leader"; // 学生干部
	} else if (grade >= 70 && isStuLeader == 'Y' && isExcellentVolunteer == 'Y') {
		isEligible = true;
		scholarType = "Comprehensive"; // 综合奖学金
	}

	if (isEligible) {
		cout << "Congratulations! You are eligible for the " << scholarType << " scholarship.\n";
	} else {
		cout << "Sorry, you are not eligible for any scholarship this semester.\n";
	}
	return 0; // 正常退出函数
}

void showEvaluation() {
	cout << "This semester's evaluation: Keep up the good work!\n";
}

int main() {
	int choice;

	while (true) {
		cout << "\nPlease select an action to perform(enter a number 1 - 4):\n";
		cout << "1. Check grade level\n";
		cout << "2. Determine if scholarship is awarded\n"; // 判断是否获得奖学金
		cout << "3. Show this semester's evaluation\n"; // 显示本学期评价
		cout << "4. Exit program\n";
		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			while (checkLevel() == 1) {
				// 重新调用函数让用户输入正确的成绩
				cout << "Invalid grade. Please enter a number between 0 and 100.\n";
			}
			break;
		case 2:
			while (true) {
                int result = checkScholarship();
                if (result == 0) {
                    break; // 正常退出，跳出循环
                } else if (result == 1) {
                    cout << "Invalid grade. Please enter a number between 0 and 100.\n";
                } else if (result == 2) {
                    cout << "Invalid input for choice. Please enter Y or N.\n";
                }
            }
            break;
		case 3:
			showEvaluation();
			break;
		case 4:
			cout << "Exiting program. Goodbye!\n";
			return 0;
		default:
			cout << "Invalid choice. Please enter a number between 1 and 4.\n";
			break;
		}
	}
}