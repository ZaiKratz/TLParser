#include "../Public/SendCode.h"


//begin namespace block
namespace AUTH
{

SendCode::SendCode()
{
	this->_ConstructorID = -2035355412;
	this->_ContentRelated = true;
}

SendCode::SendCode(bool allow_flashcall, FString phone_number, bool current_number, int32 api_id, FString api_hash)
{
	this->_ConstructorID = -2035355412;
	this->_ContentRelated = true;
	this->allow_flashcall = allow_flashcall;
	this->phone_number = phone_number;
	this->current_number = current_number;
	this->api_id = api_id;
	this->api_hash = api_hash;
}
void SendCode::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(allow_flashcall)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(current_number)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->phone_number);
	if(!this->current_number)
	{
	Writer.WriteBool(this->current_number);
	}
	Writer.WriteInt(this->api_id);
	Writer.TGWriteString(this->api_hash);
}


void SendCode::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<AUTH::SentCode*>(Reader.TGReadObject());
	this->_Responded = true;
}
SendCode::~SendCode()
{

}
}//end namespace block
