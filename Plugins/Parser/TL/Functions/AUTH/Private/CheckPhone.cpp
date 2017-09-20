#include "../Public/CheckPhone.h"


//begin namespace block
namespace AUTH
{

CheckPhone::CheckPhone()
{
	this->_ConstructorID = -81926801;
	this->_ContentRelated = true;
}

CheckPhone::CheckPhone(FString phone_number)
{
	this->_ConstructorID = -81926801;
	this->_ContentRelated = true;
	this->phone_number = phone_number;
}
void CheckPhone::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->phone_number);
}


void CheckPhone::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<AUTH::CheckedPhone*>(Reader.TGReadObject());
}
CheckPhone::~CheckPhone()
{

}
}//end namespace block
