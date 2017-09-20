#include "../Public/ImportAuthorization.h"


//begin namespace block
namespace AUTH
{

ImportAuthorization::ImportAuthorization()
{
	this->_ConstructorID = 328658915;
	this->_ContentRelated = true;
}

ImportAuthorization::ImportAuthorization(int32 id, TArray<uint8> bytes)
{
	this->_ConstructorID = 328658915;
	this->_ContentRelated = true;
	this->id = id;
	this->bytes = bytes;
}
void ImportAuthorization::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
	Writer.TGWriteBytes((unsigned char*)this->bytes.GetData(), this->bytes.Num());
}


void ImportAuthorization::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<AUTH::Authorization*>(Reader.TGReadObject());
}
ImportAuthorization::~ImportAuthorization()
{

}
}//end namespace block
