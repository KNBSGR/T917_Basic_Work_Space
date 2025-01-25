# T917_Basic_Work_Space
开发流程基础文件夹
├─00_Project_Management			/*项目管理，存放项目管理类文件*/
│  ├─00_需求导入_QFD				/*从产品端确定需求*/
│  ├─01_需求约束_Pugh				/*对需求进行多方评审*/
│  ├─02_需求转化_Basic_Statics	/*根据评审确定的最终需求转化为产品特征*/
│  ├─03_功能图谱_Function_Map		/*确定功能的具体实现方法*/
│  ├─04_功能风险管控_DFMEA		/*评估产品失效情况和开发过程中的风险点*/
│  ├─04_法规认证_国内_国外			/*评估产品功能实现是否满足相关法规*/
│  ├─04_知识产权_国内_国外			/*评估产品实现方法是否存在侵权风险，或挖掘可申请专利项目*/
│  ├─05_敏捷开发_Scrum			/*确定开发方式和具体开发人员*/
│  ├─06_持续集成与测试_DevOps		/*在开发过程中对新开发功能进行单元测试*/
│  ├─07_产品生产管理_Six_Sigma	/*提交工厂后通过VE/CE去提高产品的良品率*/
│  └─08_缺陷管理追踪_Jira			/*产品投放市场后持续收集产品缺陷，并迭代升级产品*/
├─00_Reference					/*参考文件*/
├─01_Function_Map				/*功能图谱，开发者细分*/
├─02_Hardware					/*项目硬件部分*/
│  ├─00_Ref						/*参考文件*/
│  │  └─00_HDK					/*Hardware Develop Toolkit*/
│  └─01_Project					/*硬件工程*/
├─03_Firmware					/*存放不会变更的驱动、中间件等*/
├─04_Software					/*项目软件部分*/
│  ├─00_Ref						/*参考文件*/
│  │  └─00_SDK
|  |  └─....
│  └─01_Source_Code				/*源代码*/
├─05_Mechanical					/*项目机械部分*/
├─06_FCT						/*产品批量测试工具/上位机*/
└─07_Tools						/*开发流程自动化工具/脚本*/
....

使用git bash删除每个目录下的.gitkeep文件
find . -type d -not -path "*/.git*" -exec rm -f {}/.gitkeep \;
为空文件夹增加.gitkeep文件
find ./ -type d -empty -not -path "./.git/*" -exec touch {}/.gitkeep \;
