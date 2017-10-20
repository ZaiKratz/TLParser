#include "../Public/UpdatePinnedDialogs.h"


//begin namespace block
namespace COMMON
{

UpdatePinnedDialogs::UpdatePinnedDialogs()
{
	this->_ConstructorID = -657787251;
}

UpdatePinnedDialogs::UpdatePinnedDialogs(TArray<TLBaseObject*>  order)
{
	this->_ConstructorID = -657787251;
	this->order = order;
}
void UpdatePinnedDialogs::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(order.Num())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	if(this->order.Num())
	{
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->order.Num());
	for(auto X : this->order)
	{
	if(X)
	{
	X->OnSend(Writer);
	}
	}
	}
}


void UpdatePinnedDialogs::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len16462 = Reader.ReadInt();
	for(int32 i = 0; i < Len16462; i++)
	{
	auto X = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	order.Add(X);
	}
	}
	this->_Responded = true;
}
UpdatePinnedDialogs::~UpdatePinnedDialogs()
{
}
}//end namespace block
