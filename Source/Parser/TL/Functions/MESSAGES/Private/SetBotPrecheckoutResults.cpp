#include "../Public/SetBotPrecheckoutResults.h"


//begin namespace block
namespace MESSAGES
{

SetBotPrecheckoutResults::SetBotPrecheckoutResults()
{
	this->_ConstructorID = 163765653;
	this->_ContentRelated = true;
}

SetBotPrecheckoutResults::SetBotPrecheckoutResults(bool success, unsigned long long query_id, FString error)
{
	this->_ConstructorID = 163765653;
	this->_ContentRelated = true;
	this->success = success;
	this->query_id = query_id;
	this->error = error;
}
void SetBotPrecheckoutResults::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(success)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!error.IsEmpty())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteLong(this->query_id);
	Writer.TGWriteString(this->error);
}


void SetBotPrecheckoutResults::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SetBotPrecheckoutResults::~SetBotPrecheckoutResults()
{
}
}//end namespace block
