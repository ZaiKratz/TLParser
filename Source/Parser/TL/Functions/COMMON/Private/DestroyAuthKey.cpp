#include "../Public/DestroyAuthKey.h"


//begin namespace block
namespace COMMON
{

DestroyAuthKey::DestroyAuthKey()
{
	this->_ConstructorID = -784117408;
	this->_ContentRelated = true;
}
void DestroyAuthKey::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void DestroyAuthKey::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PRIVATE::DestroyAuthKeyRes*>(Reader.TGReadObject());
	this->_Responded = true;
}
DestroyAuthKey::~DestroyAuthKey()
{

}
}//end namespace block
