#include "../Public/TopPeerCategoryChannels.h"


//begin namespace block
namespace COMMON
{

TopPeerCategoryChannels::TopPeerCategoryChannels()
{
	this->_ConstructorID = 680926486;
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
}
TopPeerCategoryChannels::~TopPeerCategoryChannels()
{

}
}//end namespace block
