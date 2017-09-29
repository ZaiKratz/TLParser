#include "../Public/ReorderPinnedDialogs.h"


//begin namespace block
namespace MESSAGES
{

ReorderPinnedDialogs::ReorderPinnedDialogs()
{
	this->_ConstructorID = -1784678844;
	this->_ContentRelated = true;
}

ReorderPinnedDialogs::ReorderPinnedDialogs(bool force, TArray<PRIVATE::InputPeer*>  order)
{
	this->_ConstructorID = -1784678844;
	this->_ContentRelated = true;
	this->force = force;
	this->order = order;
}
void ReorderPinnedDialogs::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(force)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->order.Num());
	for(auto X : this->order)
	{
	X->OnSend(Writer);
	}
}


void ReorderPinnedDialogs::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
ReorderPinnedDialogs::~ReorderPinnedDialogs()
{

}
}//end namespace block
