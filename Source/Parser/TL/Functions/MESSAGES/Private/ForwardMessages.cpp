#include "../Public/ForwardMessages.h"


//begin namespace block
namespace MESSAGES
{

ForwardMessages::ForwardMessages()
{
	this->_ConstructorID = 1888354709;
	this->_ContentRelated = true;
}

ForwardMessages::ForwardMessages(bool silent, bool background, bool with_my_score, PRIVATE::InputPeer*  from_peer, TArray<int32>  id, TArray<unsigned long long>  random_id, PRIVATE::InputPeer*  to_peer)
{
	this->_ConstructorID = 1888354709;
	this->_ContentRelated = true;
	this->silent = silent;
	this->background = background;
	this->with_my_score = with_my_score;
	this->from_peer = from_peer;
	this->id = id;
	this->random_id = random_id;
	this->to_peer = to_peer;
}
void ForwardMessages::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(silent)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(background)
	{
		Flags |= (1 << 6);
	}
	else
	{
		Flags |= 0;
	}
	if(with_my_score)
	{
		Flags |= (1 << 8);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->from_peer->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->id.Num());
	for(auto X : this->id)
	{
	Writer.WriteInt(X);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->random_id.Num());
	for(auto X : this->random_id)
	{
	Writer.WriteLong(X);
	}
	this->to_peer->OnSend(Writer);
}


void ForwardMessages::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
ForwardMessages::~ForwardMessages()
{

}
}//end namespace block
