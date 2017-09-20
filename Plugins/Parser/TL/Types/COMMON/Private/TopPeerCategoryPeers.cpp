#include "../Public/TopPeerCategoryPeers.h"


//begin namespace block
namespace COMMON
{

TopPeerCategoryPeers::TopPeerCategoryPeers()
{
	this->_ConstructorID = -1857911813;
}

TopPeerCategoryPeers::TopPeerCategoryPeers(PRIVATE::TopPeerCategory* category, int32 count, TArray<COMMON::TopPeer*> peers)
{
	this->_ConstructorID = -1857911813;
	this->category = category;
	this->count = count;
	this->peers = peers;
}
void TopPeerCategoryPeers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->category->OnSend(Writer);
	Writer.WriteInt(this->count);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->peers.Num());
	for(auto X : this->peers)
	{
	X->OnSend(Writer);
	}
}


void TopPeerCategoryPeers::OnResponce(BinaryReader& Reader)
{
	category = reinterpret_cast<PRIVATE::TopPeerCategory*>(Reader.TGReadObject());
	count = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len22204 = Reader.ReadInt();
	for(int32 i = 0; i < Len22204; i++)
	{
	auto X = reinterpret_cast<COMMON::TopPeer*>(Reader.TGReadObject());
	peers.Add(X);
	}
}
TopPeerCategoryPeers::~TopPeerCategoryPeers()
{

}
}//end namespace block
