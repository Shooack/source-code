'''
轩哥出品，必属废品！
轩哥出品，必属废品！
轩哥出品，必属废品！
轩哥出品，必属废品！
'''
def show_menu():
    print("*" * 50)
    print("欢迎使用【名片管理系统】v1.0")
    print("1.新建名片")
    print("2.显示全部名片")
    print("3.查询名片")
    print("")
    print("0.退出系统")
    print("*" * 50)


card_list = []


def new_card():
    print("-" * 50)
    print("新建名片")
    # 1.提示用户输入名片的详细信息
    name_str = input("请输入姓名：")
    tel_str = input("请输入电话号码：")
    qq_str = input("请输入QQ号码：")
    email_str = input("请输入邮箱：")
    # 2.使用用户输入的信心建立名片字典
    card_dict = {"name": name_str,
                 "tel": tel_str,
                 "qq": qq_str,
                 "email": email_str}
    # 3.将名片字典添加到列表中
    card_list.append(card_dict)
    print(card_list)
    # 4.提示用户添加成功
    print("添加%s的名片成功" % name_str)


def show_all():
    print("-" * 50)
    print("显示所有名片")
    # 判断是否存在名片记录，如果没有，提示用户，并且返回
    if len(card_list) == 0:
        print("当前没有任何的名片记录，请使用新增功能添加名片")
        return  # 下面的代码不执行
    # 打印表头
    for name in ["姓名", "电话", "QQ", "邮箱"]:
        print(name, end="\t\t")
    print("")
    # 打印分割线
    print("=" * 50)
    # 遍历名片列表依次输出字典信息
    for card_dict in card_list:
        print("%s\t\t\t%s\t\t\t%s\t\t\t%s" % (card_dict["name"],
                                              card_dict["tel"],
                                              card_dict["qq"],
                                              card_dict["email"]))


def find_card():
    print("-" * 50)
    print("查找名片")
    # 1.提示用户输入要搜索的信息
    if len(card_list) == 0:
        print("当前没有任何的名片记录，请使用新增功能添加名片")
        return  # 下面的代码不执行
    find_name = input("请输入要搜索的姓名：")
    # 2.遍历名片列表，查询要搜索的姓名，如果没有找到，需要提示用户
    for card_dict in card_list:
        if card_dict["name"] == find_name:
            print("已找到%s" % find_name)
            print("姓名\t\t电话\t\tQQ\t\t邮箱\t\t")
            print("=" * 50)
            print("%s\t\t\t%s\t\t\t%s\t\t\t%s" % (card_dict["name"],
                                                  card_dict["tel"],
                                                  card_dict["qq"],
                                                  card_dict["email"]))
            # TODO 针对找到的名片记录进行修改和删除操作
            deal_card(card_dict)
            break
    else:
        print("抱歉，没有找到%s" % find_name)


def deal_card(find_dict):
    """处理查找到的名片

    :param find_dict:查找到的名片
    """
    print(find_dict)
    action_str = input("请选择要执行的操作：【1】修改 【2】删除 【3】返回上级菜单")
    if action_str == "1":
        find_dict["name"] = input_card_info(find_dict["name"], "修改姓名[enter键不修改]：")
        find_dict["tel"] = input_card_info(find_dict["tel"], "修改电话[enter键不修改]：")
        find_dict["qq"] = input_card_info(find_dict["qq"], "修改QQ[enter键不修改]：")
        find_dict["email"] = input_card_info(find_dict["email"], "修改邮箱[enter键不修改]：")
        print("修改名片成功")
    elif action_str == "2":
        card_list.remove(find_dict)
        print("删除名片成功")


def input_card_info(find_value, tip_messenger):
    """
    输入名片信息

    :param find_value:字典中原有的值
    :param tip_messenger:输入的提示文字
    :return:如果用户输入了内容就返回内容，否则返回字典中原有的值
    """
    # 提示用户输入操作
    result_str = input(tip_messenger)
    # 针对用户输入的内容进行判断，如果输入了内容，直接返回结果
    if len(result_str) > 0:
        return result_str
    # 如果没有输入内容，返回原字典中的值
    else:
        return find_value



while True:
    # TODO 显示功能菜单
    show_menu()
    action_str = input("请选择您的操作：")
    print("您选择的操作是【%s】" % action_str)
    # 如果输入1，2，3表示针对名片的操作
    if action_str in ["1", "2", "3"]:
        # 新增名片处理
        if action_str == "1":
            new_card()
        # 显示全部名片处理
        elif action_str == "2":
            show_all()
        # 查询名片处理
        elif action_str == "3":
            find_card()
        pass

        # 如果输入0表示退出系统
    elif action_str == "0":
        print("欢迎再次使用【名片管理系统】v1.0")
        break
    # 如果输入其他内容，提示输入错误
    else:
        print("您输入的不正确，请重新输入")
    print("\n")


