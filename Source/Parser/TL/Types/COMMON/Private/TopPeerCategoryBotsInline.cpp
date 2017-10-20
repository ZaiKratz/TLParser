#include "../Public/TopPeerCategoryBotsInline.h"


//begin namespace block
namespace COMMON
{

TopPeerCategoryBotsInline::TopPeerCategoryBotsInline()
{
	this->_ConstructorID = 344356834;
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
	this->_Responded = true;
}
TopPeerCategoryBotsInline::~TopPeerCategoryBotsInline()
{
}
}//end namespace block
