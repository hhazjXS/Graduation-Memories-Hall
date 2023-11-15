#include "ThemeManager.h"

void ThemeManager::AddTheme(string theme) {
    if (theme == "GraduationMessage") {
        // ���� GraduationMessage �ಢ��ӵ� Themes ����
        GraduationMessage graduationMessage;
        Themes.push_back(graduationMessage);
        cout << "Graduation Theme added successfully.\n";
    }
    else if (theme == "MemoryMap") {
        // ���� MemoryMap �ಢ��ӵ� Themes ����
        MemoryMap memoryMap;
        Themes.push_back(memoryMap);
        cout << "Map Theme added successfully.\n";
    }
    else {
        cout << "No Related Themes\n";
    }
}

void ThemeManager::DeleteTheme(string theme) {
    auto it = find_if(Themes.begin(), Themes.end(), [theme](MessageTheme& messageTheme) {
        return messageTheme.GetTheme() == theme;
        });

    if (it != Themes.end()) {
        Themes.erase(it);
        cout << "Theme deleted successfully.\n";
    }
    else {
        cout << "Theme not found.\n";
    }
}

MessageTheme ThemeManager::GetTheme(string theme) {
    auto it = find_if(Themes.begin(), Themes.end(), [theme](MessageTheme& messageTheme) {
        return messageTheme.GetTheme() == theme;
        });

    if (it != Themes.end()) {
        return *it;
    }
    else {
        cout << "Theme not found.\n";
        return MessageTheme();
    }
}
