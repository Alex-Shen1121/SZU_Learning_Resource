def displayInventory(mp: map):
    print('Inventory:')
    for item in mp.items():
        print(item[1], item[0])
    print('Total number of items:', sum(mp.values()))


if __name__ == '__main__':
    mp = {'rope': 1, 'torch': 6, 'gold coin': 42,
          'dagger': 1, 'arrow': 12}
    displayInventory(mp)
