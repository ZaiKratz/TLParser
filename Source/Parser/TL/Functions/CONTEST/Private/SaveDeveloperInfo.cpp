#include "../Public/SaveDeveloperInfo.h"


//begin namespace block
namespace CONTEST
{

SaveDeveloperInfo::SaveDeveloperInfo()
{
	this->_ConstructorID = -1705021803;
	this->_ContentRelated = true;
}

SaveDeveloperInfo::SaveDeveloperInfo(int32 vk_id, FString name, FString phone_number, int32 age, FString city)
{
	this->_ConstructorID = -1705021803;
	this->_ContentRelated = true;
	this->vk_id = vk_id;
	this->name = name;
	this->phone_number = phone_number;
	this->age = age;
	this->city = city;
}
void SaveDeveloperInfo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->vk_id);
	Writer.TGWriteString(this->name);
	Writer.TGWriteString(this->phone_number);
	Writer.WriteInt(this->age);
	Writer.TGWriteString(this->city);
}


void SaveDeveloperInfo::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SaveDeveloperInfo::~SaveDeveloperInfo()
{

}
}//end namespace block
