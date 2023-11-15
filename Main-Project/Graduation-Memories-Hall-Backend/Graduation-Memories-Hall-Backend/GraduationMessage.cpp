#include "GraduationMessage.h"

void GraduationMessage::AddBox(string university, string major) {
    // ����Ƿ������ͬ��ѧ��רҵ�� MessageBox
    for (MessageBox& box : GraduationBox) {
        if (box.GetUniversity() == university && box.GetMajor() == major) {
            cout << "A MessageBox for this university and major already exists.\n";
            return;
        }
    }

    // �����µ� MessageBox ���󲢼��� GraduationBox ������
    Coordinate position{ 0.0, 0.0 };  // �������Ҫ�ṩ������Ϣ
    MessageBox newMessageBox(position, university, major);
    GraduationBox.push_back(newMessageBox);

    // �����ʾ��Ϣ
    cout << "MessageBox added successfully.\n";
}

void GraduationMessage::DeleteBox(string university, string major) {
    // ���Ҳ�ɾ����ͬ��ѧ��רҵ�� MessageBox
    auto it = std::remove_if(GraduationBox.begin(), GraduationBox.end(), [university, major](MessageBox& box) {
        return box.GetUniversity() == university && box.GetMajor() == major;
        });

    // ����Ƿ��ҵ���ɾ���� MessageBox
    if (it != GraduationBox.end()) {
        GraduationBox.erase(it, GraduationBox.end());
        cout << "MessageBox deleted successfully.\n";
    }
    else {
        cout << "No MessageBox found for this university and major.\n";
    }
}

MessageBox GraduationMessage::GetBox(string university, string major) {
    // ������ͬ��ѧ��רҵ�� MessageBox
    auto it = std::find_if(GraduationBox.begin(), GraduationBox.end(), [university, major](MessageBox& box) {
        return box.GetUniversity() == university && box.GetMajor() == major;
        });

    // ����Ƿ��ҵ��� MessageBox
    if (it != GraduationBox.end()) {
        return *it;
    }
    else {
        // ����һ���յ� MessageBox ���󣬱�ʾδ�ҵ�
        cout << "No MessageBox found for this university and major.\n";
        return MessageBox(Coordinate{ 0.0, 0.0 }, "", "");
    }
}
