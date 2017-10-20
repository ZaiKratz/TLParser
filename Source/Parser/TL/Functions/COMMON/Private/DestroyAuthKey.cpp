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
	this->result = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	this->_Responded = true;
}
DestroyAuthKey::~DestroyAuthKey()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
