#include "../Public/ExportedAuthorization.h"


//begin namespace block
namespace AUTH
{

ExportedAuthorization::ExportedAuthorization()
{
	this->_ConstructorID = -543777747;
}

ExportedAuthorization::ExportedAuthorization(int32 id, TArray<uint8>  bytes)
{
	this->_ConstructorID = -543777747;
	this->id = id;
	this->bytes = bytes;
}
void ExportedAuthorization::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
	Writer.TGWriteBytes((unsigned char*)this->bytes.GetData(), this->bytes.Num());
}


void ExportedAuthorization::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
	bytes = Reader.TGReadBytes();
	this->_Responded = true;
}
ExportedAuthorization::~ExportedAuthorization()
{

}
}//end namespace block
