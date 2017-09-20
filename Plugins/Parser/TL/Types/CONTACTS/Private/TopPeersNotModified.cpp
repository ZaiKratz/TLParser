#include "../Public/TopPeersNotModified.h"


//begin namespace block
namespace CONTACTS
{

TopPeersNotModified::TopPeersNotModified()
{
	this->_ConstructorID = -177330466;
}
void TopPeersNotModified::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void TopPeersNotModified::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
TopPeersNotModified::~TopPeersNotModified()
{

}
}//end namespace block
