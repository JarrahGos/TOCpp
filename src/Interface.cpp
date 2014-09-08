#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtGui>
#include <QGridLayout>
#include <QFont>
#include <QTextBlock>
#include <QPushButton>
#include <QLineEdit>
#include <QListView>
#include <QActionGroup>
#include <QQuickView>



class Interface
{
private:
    int horizontalSize;
    int verticalSize;
    int logicalSize;
    WorkingUser workingUser;
    void enterPassword();
    void enterAdminMode();
public:
    void userMode();
    int main(int, char*);
};

int main(int argc, char *argv[])
{
    for(int i = argc; i > 0; i--) {
        if(argv[i] == ("-w") && i!= argc-1) {
            horizontalSize = Integer.parseInt(argv[i+1]);
        }
        else if(argv[i] == ("-h") && i != argc-1) {
            verticalSize = Integer.parseInt(argv[i+1]);
        }
    }
    //QApplication app(argc, argv);

    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:///UserInterface.qml")));

    return app.exec();
}
void userMode()
{
    QWindow userWindow;
    userWindow.setTitle("TOC19");
    workingUser.addDatabases();
//    QGridLayout grid = new QGridLayout();
//    grid.setVerticalSpacing(10);
//    grid.setHorizontalSpacing(10);
//
//    QTextBlock inputLabel = new QTextBlock("Enter your PMKeyS:");
//    grid.addItem(inputLabel, 0,0);

//    QLineEdit input = new QLineEdit();
//    grid.addItem(input, 1,0);
//    input.requestFocus();
//    QTextBlock userLabel = new QTextBlock("Error");

//    QTextBlock totalLabel = new QTextBlock("            Total:");
//    grid.addItem(totalLabel, 2,8);
 //   QLineEdit total = new QLineEdit(); // this should contain the total cost.
//    total.setEditible(false);
//    gird.add(total, 3,8);

//    QPushButton enterBarCode = new QPushButton("OK");
//    grid.addItem(enterBarCode, 2,0, 2,1);


//    QListView itemList = new QListView();
    // create the main user window.
    QQuickView *userView = new QQuickView;
    userView->setSource(QUrl::fromLocalFile("UserInterface.qml"));
    userView->show();




}
