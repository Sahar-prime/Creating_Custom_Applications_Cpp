#include <iostream>

//#define H_W_2

// Структура для задачи
struct Task
{
    char* taskName;          // Название задачи (динамическая строка)
    char* taskDescription;   // Описание задачи (динамическая строка)
    bool taskStatus;         // Статус задачи: true - выполнена, false - не выполнена
};

// Структура для проекта
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

// Функция для инициализации задачи
void initTask(Task& task, const char* name, const char* description, bool status) 
{
    copyString(task.taskName, name);
    copyString(task.taskDescription, description);
    task.taskStatus = status;
}

// Функция для освобождения памяти задачи
void freeTask(Task& task) 
{
    delete[] task.taskName;
    delete[] task.taskDescription;
}

// Функция для инициализации проекта
void initProject(SoftwareProject& project, const char* name, const char* description)
{
    copyString(project.projectName, name);
    copyString(project.projectDescription, description);
    project.tasks = nullptr;
    project.taskCount = 0;
}

// Функция для освобождения памяти проекта
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

// Функция для добавления задачи в проект
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
    initProject(myProject, "Калькулятор", "Проект для решения простых примеров.");

    // Добавление задач
    addTask(myProject, "Сложение", "Сложить введеные числа", true);
    addTask(myProject, "Вычитание", "Вычесть введеные числа", true);
    addTask(myProject, "Умножение", "Умножить введеные числа", true);
    addTask(myProject, "Деление", "Делить введеные числа", true);
    addTask(myProject, "Степени", "Возводить в степень введеные числа", false);
    addTask(myProject, "Корни", "Возводить в корень введеные числа", false);
    
    // Вывод информации о проекте
    std::cout << "Название проекта: " << myProject.projectName << std::endl;
    std::cout << "Описание проекта: " << myProject.projectDescription << std::endl;
    std::cout << "Список задач:" << std::endl;

    for (int i = 0; i < myProject.taskCount; ++i)
    {
        std::cout << "- " << myProject.tasks[i].taskName << " (Статус: " << (myProject.tasks[i].taskStatus ? "выполнена" : "не выполнена") << ")" << std::endl;
        std::cout << "  Описание: " << myProject.tasks[i].taskDescription << std::endl;
    }

    // Освобождение памяти
    freeProject(myProject);
}
#endif //H_W_2