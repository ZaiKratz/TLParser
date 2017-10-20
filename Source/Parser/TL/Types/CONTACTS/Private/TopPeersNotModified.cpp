#include "../Public/TopPeersNotModified.h"


//begin namespace block
namespace CONTACTS
{

TopPeersNotModified::TopPeersNotModified()
{
	this->_ConstructorID = -567906571;
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
	this->_Responded = true;
}
TopPeersNotModified::~TopPeersNotModified()
{
}
}//end namespace block
