#include "../Public/SaveBigFilePart.h"


//begin namespace block
namespace UPLOAD
{

SaveBigFilePart::SaveBigFilePart()
{
	this->_ConstructorID = -562337987;
	this->_ContentRelated = true;
}

SaveBigFilePart::SaveBigFilePart(unsigned long long file_id, int32 file_part, int32 file_total_parts, TArray<uint8>  bytes)
{
	this->_ConstructorID = -562337987;
	this->_ContentRelated = true;
	this->file_id = file_id;
	this->file_part = file_part;
	this->file_total_parts = file_total_parts;
	this->bytes = bytes;
}
void SaveBigFilePart::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->file_id);
	Writer.WriteInt(this->file_part);
	Writer.WriteInt(this->file_total_parts);
	Writer.TGWriteBytes((unsigned char*)this->bytes.GetData(), this->bytes.Num());
}


void SaveBigFilePart::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SaveBigFilePart::~SaveBigFilePart()
{
}
}//end namespace block
