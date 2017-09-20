#include "../Public/GetWallPapers.h"


//begin namespace block
namespace ACCOUNT
{

GetWallPapers::GetWallPapers()
{
	this->_ConstructorID = -1023783744;
	this->_ContentRelated = true;
}
void GetWallPapers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetWallPapers::OnResponce(BinaryReader& Reader)
{
}
GetWallPapers::~GetWallPapers()
{

}
}//end namespace block
