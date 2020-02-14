#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtPlugin>
#include <string>
#include <fstream>
#include <thread>
#include <iostream>


static void PrintFileContent (const char * filename) {
    std::ifstream myfile (filename);
    if (!myfile.is_open())
        return;
    
    std::string line;
    while (getline(myfile,line))
        std::cout << line << '\n';
}

void ThreadFunction () {
    std::cout << "Hello thread\n";
}

int main(int argc, char *argv[])
{
    PrintFileContent("example.txt");
	
	try {
		throw std::runtime_error("Hello runtime_error\n");
	} catch (std::exception & e) {
		std::cout << "EXCEPTION: " << e.what();
	}

    try {
        std::thread t(&ThreadFunction);
        t.join();
        std::cout << "Thread joined\n";
    } catch (std::exception & e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return -1;
    }

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
