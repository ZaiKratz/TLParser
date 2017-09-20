#include "../Public/TopPeerCategoryBotsInline.h"


//begin namespace block
namespace COMMON
{

TopPeerCategoryBotsInline::TopPeerCategoryBotsInline()
{
	this->_ConstructorID = -495483372;
}
void TopPeerCategoryBotsInline::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void TopPeerCategoryBotsInline::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
TopPeerCategoryBotsInline::~TopPeerCategoryBotsInline()
{

}
}//end namespace block
