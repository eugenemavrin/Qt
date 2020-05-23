#include <iostream>
#include <QDebug>
#include "modules/json.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    Json::JsonValue x = Json::JsonValue(false);
    qDebug() << x.isBool();
    x.toInt();
    auto y = x.toArray();
    qDebug() << y.isEmpty();
    return 0;
}
