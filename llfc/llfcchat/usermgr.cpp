#include "usermgr.h"

UserMgr::~UserMgr()
{

}

void UserMgr::SetName(QString name)
{
    _name = name;
}

void UserMgr::SetUid(int uid)
{
    _uid = uid;
}

void UserMgr::SetToken(QString token)
{
    _token = token;
}

UserMgr::UserMgr()
{

}

int UserMgr::GetUid()
{
    return _user_info->_uid;
}

QString UserMgr::GetName()
{
    return _user_info->_name;
}

std::vector<std::shared_ptr<ApplyInfo> > UserMgr::GetApplyList()
{
    return _apply_list;
}

bool UserMgr::AlreadyApply(int uid)
{
    for(auto& apply: _apply_list){
        if(apply->_uid == uid){
            return true;
        }
    }

    return false;
}

void UserMgr::AddApplyList(std::shared_ptr<ApplyInfo> app)
{
    _apply_list.push_back(app);
}

void UserMgr::SetUserInfo(std::shared_ptr<UserInfo> user_info)
{
    _user_info = user_info;
}

void UserMgr::AppendApplyList(QJsonArray array)
{
    // 遍历 QJsonArray 并输出每个元素
    for (const QJsonValue &value : array) {
        auto name = value["name"].toString();
        auto desc = value["desc"].toString();
        auto icon = value["icon"].toString();
        auto nick = value["nick"].toString();
        auto sex = value["sex"].toInt();
        auto uid = value["uid"].toInt();
        auto status = value["status"].toInt();
        auto info = std::make_shared<ApplyInfo>(uid, name,
                                                desc, icon, nick, sex, status);
        _apply_list.push_back(info);
    }
}

// void UserMgr::AppendFriendList(QJsonArray array) {
//     // 遍历 QJsonArray 并输出每个元素
//     for (const QJsonValue& value : array) {
//         auto name = value["name"].toString();
//         auto desc = value["desc"].toString();
//         auto icon = value["icon"].toString();
//         auto nick = value["nick"].toString();
//         auto sex = value["sex"].toInt();
//         auto uid = value["uid"].toInt();
//         auto back = value["back"].toString();

//         auto info = std::make_shared<FriendInfo>(uid, name,
//                                                  nick, icon, sex, desc, back);
//         _friend_list.push_back(info);
//         _friend_map.insert(uid, info);
//     }
// }
