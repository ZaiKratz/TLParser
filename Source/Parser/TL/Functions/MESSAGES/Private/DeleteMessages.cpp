#include "../Public/DeleteMessages.h"


//begin namespace block
namespace MESSAGES
{

DeleteMessages::DeleteMessages()
{
	this->_ConstructorID = -443640366;
	this->_ContentRelated = true;
}

DeleteMessages::DeleteMessages(bool revoke, TArray<int32>  id)
{
	this->_ConstructorID = -443640366;
	this->_ContentRelated = true;
	this->revoke = revoke;
	this->id = id;
}
void DeleteMessages::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(revoke)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->id.Num());
	for(auto X : this->id)
	{
	Writer.WriteInt(X);
	}
}


void DeleteMessages::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::AffectedMessages*>(Reader.TGReadObject());
	this->_Responded = true;
}
DeleteMessages::~DeleteMessages()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
