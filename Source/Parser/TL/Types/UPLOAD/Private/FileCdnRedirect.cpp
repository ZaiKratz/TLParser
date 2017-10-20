#include "../Public/FileCdnRedirect.h"


//begin namespace block
namespace UPLOAD
{

FileCdnRedirect::FileCdnRedirect()
{
	this->_ConstructorID = -363659686;
}

FileCdnRedirect::FileCdnRedirect(int32 dc_id, TArray<uint8>  file_token, TArray<uint8>  encryption_key, TArray<uint8>  encryption_iv, TArray<COMMON::CdnFileHash*>  cdn_file_hashes)
{
	this->_ConstructorID = -363659686;
	this->dc_id = dc_id;
	this->file_token = file_token;
	this->encryption_key = encryption_key;
	this->encryption_iv = encryption_iv;
	this->cdn_file_hashes = cdn_file_hashes;
}
void FileCdnRedirect::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->dc_id);
	Writer.TGWriteBytes((unsigned char*)this->file_token.GetData(), this->file_token.Num());
	Writer.TGWriteBytes((unsigned char*)this->encryption_key.GetData(), this->encryption_key.Num());
	Writer.TGWriteBytes((unsigned char*)this->encryption_iv.GetData(), this->encryption_iv.Num());
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->cdn_file_hashes.Num());
	for(auto X : this->cdn_file_hashes)
	{
	X->OnSend(Writer);
	}
}


void FileCdnRedirect::OnResponce(BinaryReader& Reader)
{
	dc_id = Reader.ReadInt();
	file_token = Reader.TGReadBytes();
	encryption_key = Reader.TGReadBytes();
	encryption_iv = Reader.TGReadBytes();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len30310 = Reader.ReadInt();
	for(int32 i = 0; i < Len30310; i++)
	{
	auto X = reinterpret_cast<COMMON::CdnFileHash*>(Reader.TGReadObject());
	cdn_file_hashes.Add(X);
	}
	this->_Responded = true;
}
FileCdnRedirect::~FileCdnRedirect()
{
}
}//end namespace block
