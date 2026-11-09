#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tasks[20];
    string times[20];
    string priority[20];
    string status[20];

    int taskCount = 0;
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "       SMART TASK MANAGER\n";
        cout << "====================================\n";
        cout << "1. Add Task\n";
        cout << "2. Show All Tasks\n";
        cout << "3. Show Important Tasks\n";
        cout << "4. Suggest a Task\n";
        cout << "5. Show Reminders\n";
        cout << "6. Mark Task as Completed\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        // ================= ADD TASK =================
        case 1:
            if (taskCount < 20)
            {
                cin.ignore();

                cout << "\nEnter task: ";
                getline(cin, tasks[taskCount]);

                cout << "Enter task time: ";
                getline(cin, times[taskCount]);

                cout << "Choose priority:\n";
                cout << "1. High\n";
                cout << "2. Medium\n";
                cout << "3. Low\n";

                int p;
                cout << "Enter choice: ";
                cin >> p;

                if (p == 1)
                    priority[taskCount] = "High";
                else if (p == 2)
                    priority[taskCount] = "Medium";
                else
                    priority[taskCount] = "Low";

                status[taskCount] = "Pending";

                taskCount++;

                cout << "\nTask added successfully!\n";
            }
            else
            {
                cout << "\nTask list is full!\n";
            }
            break;


        // ================= SHOW ALL TASKS =================
        case 2:
            cout << "\n========== ALL TASKS ==========\n";

            if (taskCount == 0)
            {
                cout << "No tasks available.\n";
            }
            else
            {
                for (int i = 0; i < taskCount; i++)
                {
                    cout << "\nTask " << i + 1 << endl;
                    cout << "Name: " << tasks[i] << endl;
                    cout << "Time: " << times[i] << endl;
                    cout << "Priority: " << priority[i] << endl;
                    cout << "Status: " << status[i] << endl;
                }
            }
            break;


        // ================= IMPORTANT TASKS =================
        case 3:
            cout << "\n======= IMPORTANT TASKS =======\n";

            for (int i = 0; i < taskCount; i++)
            {
                if (priority[i] == "High")
                {
                    cout << i + 1 << ". "
                         << tasks[i] << " | "
                         << times[i] << " | "
                         << status[i] << endl;
                }
            }
            break;


        // ================= SUGGESTIONS =================
        case 4:
        {
            int suggestionType;
            int suggestionChoice;
            int addChoice;

            cout << "\n======= SUGGESTIONS =======\n";
            cout << "1. Study Suggestions\n";
            cout << "2. Sport Suggestions\n";
            cout << "3. Entertainment Suggestions\n";
            cout << "4. Back to Main Menu\n";

            cout << "Enter your choice: ";
            cin >> suggestionType;

            string suggestedTask = "";

            switch (suggestionType)
            {
            // -------- STUDY --------
            case 1:
                cout << "\n--- Study Suggestions ---\n";
                cout << "1. Learn C++\n";
                cout << "2. Read a Book\n";
                cout << "3. Review Your Lessons\n";
                cout << "4. Back\n";

                cout << "Choose a suggestion: ";
                cin >> suggestionChoice;

                if (suggestionChoice == 1)
                    suggestedTask = "Learn C++";
                else if (suggestionChoice == 2)
                    suggestedTask = "Read a Book";
                else if (suggestionChoice == 3)
                    suggestedTask = "Review Your Lessons";
                else if (suggestionChoice == 4)
                    break;
                else
                    cout << "Invalid choice!\n";

                break;


            // -------- SPORT --------
            case 2:
                cout << "\n--- Sport Suggestions ---\n";
                cout << "1. Exercise\n";
                cout << "2. Watch Real Madrid\n";
                cout << "3. Watch Barcelona\n";
                cout << "4. Back\n";

                cout << "Choose a suggestion: ";
                cin >> suggestionChoice;

                if (suggestionChoice == 1)
                    suggestedTask = "Exercise";
                else if (suggestionChoice == 2)
                    suggestedTask = "Watch Real Madrid";
                else if (suggestionChoice == 3)
                    suggestedTask = "Watch Barcelona";
                else if (suggestionChoice == 4)
                    break;
                else
                    cout << "Invalid choice!\n";

                break;


            // -------- ENTERTAINMENT --------
            case 3:
                cout << "\n--- Entertainment Suggestions ---\n";
                cout << "1. Watch Real Madrid\n";
                cout << "2. Watch Barcelona\n";
                cout << "3. Watch a Movie\n";
                cout << "4. Read a Book\n";
                cout << "5. Take a Break\n";
                cout << "6. Back\n";

                cout << "Choose a suggestion: ";
                cin >> suggestionChoice;

                if (suggestionChoice == 1)
                    suggestedTask = "Watch Real Madrid";
                else if (suggestionChoice == 2)
                    suggestedTask = "Watch Barcelona";
                else if (suggestionChoice == 3)
                    suggestedTask = "Watch a Movie";
                else if (suggestionChoice == 4)
                    suggestedTask = "Read a Book";
                else if (suggestionChoice == 5)
                    suggestedTask = "Take a Break";
                else if (suggestionChoice == 6)
                    break;
                else
                    cout << "Invalid choice!\n";

                break;


            // -------- BACK --------
            case 4:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
            }


            // Add suggestion to tasks
            if (suggestedTask != "")
            {
                if (taskCount < 20)
                {
                    cout << "\nYou selected: "
                         << suggestedTask << endl;

                    cout << "Add this suggestion to your tasks?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";
                    cout << "Enter choice: ";
                    cin >> addChoice;

                    if (addChoice == 1)
                    {
                        tasks[taskCount] = suggestedTask;
                        times[taskCount] = "No time";
                        priority[taskCount] = "Low";
                        status[taskCount] = "Pending";

                        taskCount++;

                        cout << "\nTask added successfully!\n";
                    }
                    else
                    {
                        cout << "\nSuggestion was not added.\n";
                    }
                }
                else
                {
                    cout << "\nTask list is full!\n";
                }
            }

            break;
        }


        // ================= REMINDERS =================
        case 5:
            cout << "\n========== REMINDERS ==========\n";

            for (int i = 0; i < taskCount; i++)
            {
                if (status[i] == "Pending" &&
                    times[i] != "No time")
                {
                    cout << "Reminder: "
                         << tasks[i]
                         << " at "
                         << times[i] << endl;
                }
            }
            break;


        // ================= COMPLETE TASK =================
        case 6:
            if (taskCount == 0)
            {
                cout << "\nNo tasks available.\n";
            }
            else
            {
                int number;

                cout << "\nEnter task number: ";
                cin >> number;

                if (number >= 1 && number <= taskCount)
                {
                    status[number - 1] = "Completed";
                    cout << "Task marked as completed!\n";
                }
                else
                {
                    cout << "Invalid task number!\n";
                }
            }
            break;


        // ================= EXIT =================
        case 7:
            cout << "\nThank you for using Smart Task Manager!\n";
            break;


        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}

