#include "../Public/SaveFilePart.h"


//begin namespace block
namespace UPLOAD
{

SaveFilePart::SaveFilePart()
{
	this->_ConstructorID = -1291540959;
	this->_ContentRelated = true;
}

SaveFilePart::SaveFilePart(unsigned long long file_id, int32 file_part, TArray<uint8>  bytes)
{
	this->_ConstructorID = -1291540959;
	this->_ContentRelated = true;
	this->file_id = file_id;
	this->file_part = file_part;
	this->bytes = bytes;
}
void SaveFilePart::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->file_id);
	Writer.WriteInt(this->file_part);
	Writer.TGWriteBytes((unsigned char*)this->bytes.GetData(), this->bytes.Num());
}


void SaveFilePart::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SaveFilePart::~SaveFilePart()
{
}
}//end namespace block
