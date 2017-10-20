#include "../Public/TopPeerCategoryChannels.h"


//begin namespace block
namespace COMMON
{

TopPeerCategoryChannels::TopPeerCategoryChannels()
{
	this->_ConstructorID = 371037736;
}
void TopPeerCategoryChannels::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void TopPeerCategoryChannels::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
TopPeerCategoryChannels::~TopPeerCategoryChannels()
{
}
}//end namespace block
