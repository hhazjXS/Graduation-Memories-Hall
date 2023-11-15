#include "MemoryMap.h"

void MemoryMap::AddBox(Coordinate coordinate, string university, string major) {
	// ����Ƿ������ͬ����� MessageBox
    for (MessageBox& box : MapBoxes) {
        if (box.GetPosition().Latitude == coordinate.Latitude && box.GetPosition().Longitude == coordinate.Longitude) {
            cout << "A MessageBox already exists at this coordinate.\n";
            return;
        }
    }

    // �����µ� MessageBox ���󲢼��� MapBoxes ������
    MessageBox newMessageBox(coordinate, university, major);
    MapBoxes.push_back(newMessageBox);

    // �����ʾ��Ϣ
    cout << "MessageBox added successfully.\n";
}

void MemoryMap::DeleteBox(Coordinate coordinate) {
    // ���Ҳ�ɾ����ͬ����� MessageBox
    auto it = std::remove_if(MapBoxes.begin(), MapBoxes.end(), [coordinate](MessageBox& box) {
        return box.GetPosition().Latitude == coordinate.Latitude && box.GetPosition().Longitude == coordinate.Longitude;
        });

    // ����Ƿ��ҵ���ɾ���� MessageBox
    if (it != MapBoxes.end()) {
        MapBoxes.erase(it, MapBoxes.end());
        cout << "MessageBox deleted successfully.\n";
    }
    else {
        cout << "No MessageBox found at this coordinate.\n";
    }
}

MessageBox MemoryMap::GetBox(Coordinate coordinate) {
    // ������ͬ����� MessageBox
    auto it = std::find_if(MapBoxes.begin(), MapBoxes.end(), [coordinate](MessageBox& box) {
        return box.GetPosition().Latitude == coordinate.Latitude && box.GetPosition().Longitude == coordinate.Longitude;
        });

    // ����Ƿ��ҵ��� MessageBox
    if (it != MapBoxes.end()) {
        return *it;
    }
    else {
        // ����һ���յ� MessageBox ���󣬱�ʾδ�ҵ�
        cout << "No MessageBox found at this coordinate.\n";
        return MessageBox(Coordinate{ 0.0, 0.0 }, "", "");
    }
}
