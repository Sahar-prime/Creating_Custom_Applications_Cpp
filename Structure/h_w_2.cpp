#include <iostream>

//#define H_W_2

// ��������� ��� ������
struct Task
{
    char* taskName;          // �������� ������ (������������ ������)
    char* taskDescription;   // �������� ������ (������������ ������)
    bool taskStatus;         // ������ ������: true - ���������, false - �� ���������
};

// ��������� ��� �������
struct SoftwareProject 
{
    char* projectName;            
    char* projectDescription; 
    Task* tasks;                 
    int taskCount;      
};

void copyString(char*& dest, const char* src) 
{
    int length = 0;
    while (src[length] != '\0') 
    {
        length++;
    }
    dest = new char[length + 1];
    for (int i = 0; i <= length; i++)
    {
        dest[i] = src[i];
    }
}

// ������� ��� ������������� ������
void initTask(Task& task, const char* name, const char* description, bool status) 
{
    copyString(task.taskName, name);
    copyString(task.taskDescription, description);
    task.taskStatus = status;
}

// ������� ��� ������������ ������ ������
void freeTask(Task& task) 
{
    delete[] task.taskName;
    delete[] task.taskDescription;
}

// ������� ��� ������������� �������
void initProject(SoftwareProject& project, const char* name, const char* description)
{
    copyString(project.projectName, name);
    copyString(project.projectDescription, description);
    project.tasks = nullptr;
    project.taskCount = 0;
}

// ������� ��� ������������ ������ �������
void freeProject(SoftwareProject& project) 
{
    delete[] project.projectName;
    delete[] project.projectDescription;

    for (int i = 0; i < project.taskCount; ++i)
    {
        freeTask(project.tasks[i]);
    }

    delete[] project.tasks;
}

// ������� ��� ���������� ������ � ������
void addTask(SoftwareProject& project, const char* name, const char* description, bool status)
{
    Task* newTasks = new Task[project.taskCount + 1];

    for (int i = 0; i < project.taskCount; ++i) 
    {
        newTasks[i] = project.tasks[i];
    }

    initTask(newTasks[project.taskCount], name, description, status);

    delete[] project.tasks;
    project.tasks = newTasks;
    project.taskCount++;
}

#ifdef H_W_2
int main()
{
    setlocale(LC_ALL, "");

    SoftwareProject myProject;
    initProject(myProject, "�����������", "������ ��� ������� ������� ��������.");

    // ���������� �����
    addTask(myProject, "��������", "������� �������� �����", true);
    addTask(myProject, "���������", "������� �������� �����", true);
    addTask(myProject, "���������", "�������� �������� �����", true);
    addTask(myProject, "�������", "������ �������� �����", true);
    addTask(myProject, "�������", "��������� � ������� �������� �����", false);
    addTask(myProject, "�����", "��������� � ������ �������� �����", false);
    
    // ����� ���������� � �������
    std::cout << "�������� �������: " << myProject.projectName << std::endl;
    std::cout << "�������� �������: " << myProject.projectDescription << std::endl;
    std::cout << "������ �����:" << std::endl;

    for (int i = 0; i < myProject.taskCount; ++i)
    {
        std::cout << "- " << myProject.tasks[i].taskName << " (������: " << (myProject.tasks[i].taskStatus ? "���������" : "�� ���������") << ")" << std::endl;
        std::cout << "  ��������: " << myProject.tasks[i].taskDescription << std::endl;
    }

    // ������������ ������
    freeProject(myProject);
}
#endif //H_W_2