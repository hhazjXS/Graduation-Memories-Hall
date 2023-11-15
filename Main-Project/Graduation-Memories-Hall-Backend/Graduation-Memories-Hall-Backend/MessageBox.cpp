#include "MessageBox.h"

void MessageBox::AddMessage(string content, string owner, bool permit) {
    // ��ȡ��ǰʱ��
    time_t currentDate = time(nullptr);

    // �����µ���Ϣ���󲢼��� Messages ������
    Message newMessage(content, currentDate, owner, permit);
    Messages.push_back(newMessage);

    // �����ʾ��Ϣ
    cout << "Message added successfully.\n";
}

void MessageBox::DeleteMessage(int index) {
    // ��� index ����Ч��
    if (index < 0 || index >= Messages.size()) {
        cout << "Invalid message index.\n";
        return;
    }

    // �� Messages ������ɾ��ָ����������Ϣ
    Messages.erase(Messages.begin() + index);

    // �����ʾ��Ϣ
    cout << "Message deleted successfully.\n";
}

Message MessageBox::GetMessage(int index) {
    // ��� index ����Ч��
    if (index < 0 || index >= Messages.size()) {
        cout << "Invalid message index.\n";
        // ����һ���յ���Ϣ���󣬱�ʾ��Ч
        return Message("", 0, "", false);
    }

    // ����ָ����������Ϣ
    return Messages[index];
}

Coordinate MessageBox::GetPosition()
{
    return this->Position;
}

string MessageBox::GetUniversity()
{
    return this->University;
}

string MessageBox::GetMajor()
{
    return this->Major;
}
