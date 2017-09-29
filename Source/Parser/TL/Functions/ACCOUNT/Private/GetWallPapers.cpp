#include "../Public/GetWallPapers.h"


//begin namespace block
namespace ACCOUNT
{

GetWallPapers::GetWallPapers()
{
	this->_ConstructorID = -1068696894;
	this->_ContentRelated = true;
}
void GetWallPapers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetWallPapers::OnResponce(BinaryReader& Reader)
{
	this->_Responded = true;
}
GetWallPapers::~GetWallPapers()
{

}
}//end namespace block
