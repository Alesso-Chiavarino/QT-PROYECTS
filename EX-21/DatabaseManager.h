// DatabaseManager.h

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>

class DatabaseManager {
public:
    DatabaseManager();  // Constructor

    // Método para autenticar al usuario
    bool authenticate(const QString& username, const QString& password);
};

#endif // DATABASEMANAGER_H
