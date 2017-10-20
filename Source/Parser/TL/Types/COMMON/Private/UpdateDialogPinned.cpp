#include "../Public/UpdateDialogPinned.h"


//begin namespace block
namespace COMMON
{

UpdateDialogPinned::UpdateDialogPinned()
{
	this->_ConstructorID = -686710068;
}

UpdateDialogPinned::UpdateDialogPinned(bool pinned, TLBaseObject*  peer)
{
	this->_ConstructorID = -686710068;
	this->pinned = pinned;
	this->peer = peer;
}
void UpdateDialogPinned::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(pinned)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->peer->OnSend(Writer);
}


void UpdateDialogPinned::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		pinned = true;
	}
	peer = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
UpdateDialogPinned::~UpdateDialogPinned()
{
	if(this->peer)
	{
		delete this->peer;
	}
}
}//end namespace block
